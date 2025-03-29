/*2.Write a program to create a ring topology among n number of process and message has to be passed using the pipe
in clock wise or anti clock wise direction.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 256

typedef struct
{
    int hops;
    char text[BUFFER_SIZE];
} message_t;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <number_of_processes> <message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);
    if (n <= 0)
    {
        fprintf(stderr, "The number of processes must be positive.\n");
        exit(EXIT_FAILURE);
    }
    int pipes[n][2];
    for (int i = 0; i < n; i++)
    {
        if (pipe(pipes[i]) < 0)
        {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
    }

    int index = 0;
    for (int i = 1; i < n; i++)
    {
        pid_t pid = fork();
        if (pid < 0)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            index = i;
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i == index)
        {

            close(pipes[i][1]);
        }
        else if (i == (index + 1) % n)
        {

            close(pipes[i][0]);
        }
        else
        {

            close(pipes[i][0]);
            close(pipes[i][1]);
        }
    }

    message_t msg;

    if (index == 0)
    {
        msg.hops = 0;
        strncpy(msg.text, argv[2], BUFFER_SIZE - 1);
        msg.text[BUFFER_SIZE - 1] = '\0';

        if (write(pipes[(index + 1) % n][1], &msg, sizeof(msg)) != sizeof(msg))
        {
            perror("write");
            exit(EXIT_FAILURE);
        }
        printf("Process %d initiated message: '%s'\n", index, msg.text);
    }

    if (read(pipes[index][0], &msg, sizeof(msg)) != sizeof(msg))
    {
        perror("read");
        exit(EXIT_FAILURE);
    }

    printf("Process %d received message: '%s' with hop count %d\n", index, msg.text, msg.hops);
    msg.hops++;

    if (index == 0 && msg.hops >= n)
    {
        printf("Process %d received the message after a full circle. Terminating ring.\n", index);
    }
    else
    {

        if (write(pipes[(index + 1) % n][1], &msg, sizeof(msg)) != sizeof(msg))
        {
            perror("write");
            exit(EXIT_FAILURE);
        }
        printf("Process %d forwarded message with hop count %d\n", index, msg.hops);
    }

    close(pipes[index][0]);
    close(pipes[(index + 1) % n][1]);

    if (index == 0)
    {
        for (int i = 1; i < n; i++)
        {
            wait(NULL);
        }
    }

    return 0;
}

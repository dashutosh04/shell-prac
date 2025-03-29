/*1.Write a program that creates n level process structure where each level consists of exactly one process.
Here every parent process makes some modification to the original message
and sends it to its child and this process repeats till it reached at the last child in the process tree.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 256

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <n> <message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);
    if (n < 1)
    {
        fprintf(stderr, "n must be at least 1.\n");
        exit(EXIT_FAILURE);
    }

    char message[BUFFER_SIZE];

    strncpy(message, argv[2], BUFFER_SIZE - 1);
    message[BUFFER_SIZE - 1] = '\0';

    for (int level = 0; level < n; level++)
    {
        int fd[2];
        if (pipe(fd) == -1)
        {
            perror("pipe");
            exit(EXIT_FAILURE);
        }

        pid_t pid = fork();
        if (pid < 0)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid > 0)
        {
            close(fd[0]);
            char modified[BUFFER_SIZE];
            snprintf(modified, BUFFER_SIZE, "%s->Level%d", message, level + 1);
            printf("Parent at level %d sending: %s\n", level, modified);

            if (write(fd[1], modified, strlen(modified) + 1) == -1)
            {
                perror("write");
                exit(EXIT_FAILURE);
            }
            close(fd[1]);
            wait(NULL);

            return 0;
        }
        else
        {

            close(fd[1]);
            if (read(fd[0], message, BUFFER_SIZE) <= 0)
            {
                perror("read");
                exit(EXIT_FAILURE);
            }
            close(fd[0]);
        }
    }

    printf("Final process at level %d received message: %s\n", n, message);
    return 0;
}

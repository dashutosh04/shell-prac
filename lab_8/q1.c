#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t pid1, pid2;

    printf("Parent process: PID %d\n", getpid());

    pid1 = fork();
    if (pid1 < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid1 == 0)
    {
        printf("Child 1: PID %d, Parent PID %d\n", getpid(), getppid());

        pid_t pid1_1 = fork();
        if (pid1_1 < 0)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (pid1_1 == 0)
        {
            printf("Grandchild 1: PID %d, Parent PID %d\n", getpid(), getppid());
            exit(EXIT_SUCCESS);
        }
        else
        {
            wait(NULL);
            exit(EXIT_SUCCESS);
        }
    }
    else
    {
        pid2 = fork();
        if (pid2 < 0)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (pid2 == 0)
        {

            printf("Child 2: PID %d, Parent PID %d\n", getpid(), getppid());
            exit(EXIT_SUCCESS);
        }
        else
        {
            wait(NULL);
            wait(NULL);
            printf("Parent: All child processes have terminated.\n");
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0)
    {
        printf("Hello from child (PID %d)\n", getpid());
        exit(EXIT_SUCCESS);
    }
    else
    {
        wait(NULL);
        printf("Child has terminated.\n");
    }
    return 0;
}

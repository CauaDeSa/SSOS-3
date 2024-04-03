#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int pid1 = fork();

    if (pid1 == 0)
    {
        contar(0, 50);
        exit(0);
    }

    int pid2 = fork();

    if (pid2 == 0)
    {
        contar(51, 100);
        exit(0);
    }

    //father waiting his sons
    waitpid(NULL, pid1, 0);
    waitpid(NULL, pid2, 0);

    return 0;
}

void contar(int start, int end) {
    for (int i = start; i <= end; i++)
    {
        printf("%d\n", i);
    }
}
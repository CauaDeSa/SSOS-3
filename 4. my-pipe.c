#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int fd[2];
    pipe(fd);

    int pid = fork();

    if (pid == 0){
        close(fd[0]);

        int buracoNegro = 10;

        write(fd[1], &buracoNegro, sizeof(buracoNegro));

        exit(0);
    }

    int buracoBranco;

    read(fd[0], &buracoBranco, sizeof(int));

    printf("Valor consumido pelo buraco negro: %d\n", buracoBranco);

    close(fd[1]);
    
    return 0;
}
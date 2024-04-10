#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int successiveSum(int first, int last);

int main() {
    int fd[3];
    pipe(fd);
    int value = 10000;

    int pid = fork();

    if (pid == 0){
        close(fd[0]);
        close(fd[2]);
        double buracoNegro1 = successiveSum(1, value/2);

        write(fd[1], &buracoNegro1, sizeof(buracoNegro1));
        exit(0);

    } else {
        pid = fork();

        if (pid == 0) {
            close(fd[0]);
            close(fd[2]);

            double buracoNegro2 = successiveSum(value/2 + 1, value);

            write(fd[1], &buracoNegro2, sizeof(buracoNegro2));
            exit(0);
        }
    }

    double aux;
    double buracoBranco = 0;

    for (int i = 0; i < 2; i++){
        read(fd[0], &aux, sizeof(aux));
        buracoBranco += aux;

        printf("Resultado: %0.lf\n", buracoBranco);
    }

    close(fd[1]);
    close(fd[2]);

    return 0;
}

int successiveSum(int first, int last) {
    int result = 0;

    for (int i = first; i < last + 1; i++) {
        result += i;
    }

    return result;
}
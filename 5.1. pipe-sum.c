#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void doFork(int [], int, int);
double successiveSum(int first, int last);

int main() {
    int value;
    int aux = 0;
    int size;
    double result;

    printf("Quantidade de filhos: ");
    scanf("%d", &size);

    int sons[size];
    int fd[size];
    
    pipe(fd);

    printf("Valor limite: ");
    scanf("%d", &value);

    for (int i = 0; i < size; i++)
        sons[i] = -1;

    doFork(sons, size, aux);

    int range = value / size;

    for (int i = 0; i < size; i++)
    {
        if (sons[i] == 0)
        {
            close(fd[0]);
            close(fd[2]);

            if(i == 0)
                result = successiveSum(i * range, (i + 1) * range);    
            else
                result = successiveSum((i * range) + 1, (i + 1) * range);
                    
            write(fd[1], &result, sizeof(result));
            exit(0);
        }
    }

    double buracoBranco = 0;

    for (int i = 0; i < size; i++){
        read(fd[0], &result, sizeof(result));
        buracoBranco += result;

        printf("Resultado: %0.lf\n", buracoBranco);
    }

    close(fd[1]);
    close(fd[2]);

    return 0;
}

void doFork(int sons[], int size, int aux){
    if (sons[aux] != 0)
        sons[aux] = fork();

    if(sons[aux] != 0 && aux < size - 1){
        aux++;
        doFork(sons, size, aux);
    }
}

double successiveSum(int first, int last) {
    double result = 0;

    for (int i = first; i < last + 1; i++) {
        result += i;
    }

    return result;
}
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

void createSons(int[], int, int);
void contar(int, int);

int main(int argc, char const *argv[])
{
    int N, M;

    printf("Enter the range of numbers to count: ");
    scanf("%d", &N);
    printf("Enter the numbers of sons to count: ");
    scanf("%d", &M);

    int sons[M];

    for (int i = 0; i < M; i++){
        sons[i] = -1;
    }

    int range = N / M;
    int aux = 0;

    createSons(sons, M, aux);

    for (int i = 0; i < M; i++)
    {
        if (sons[i] == 0)
        {
            if(i == 0)
                contar(i * range, (i + 1) * range);    
            else
                contar((i * range) + 1, (i + 1) * range);
        }
    }

    return 0;
}

void contar(int start, int end) {
    for (int i = start; i <= end; i++)
    {
        printf("%d\n", i);
    }
}

void createSons(int sons[], int size, int aux){
    if (sons[aux] != 0)
        sons[aux] = fork();

    if(sons[aux] != 0 && aux < size - 1){
        aux++;
        createSons(sons, size, aux);
    }
}
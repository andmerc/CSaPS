#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    const int N = 10;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;
    
    pid_t pid = fork();
    switch(pid)
    {
        case -1:
            perror("fork");
            exit(1);
        case 0:
            for(int i = N / 2; i < N; i++)
            {
                sum += a[i];
            }
            exit(sum);
        default:
            for(int i = 0; i < N / 2; i++)
            {
                sum += a[i];
            }
            int status;
            wait(&status);
            printf("Сумма элементов массива: %d", sum + WEXITSTATUS(status));
    }
    
    return 0;
}

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Не хватает аргументов. Использование: program 'filename'");
    }
    else
    {
        char* filename = argv[1];
        int descriptor = open(filename, O_RDONLY);
    
        if (descriptor != -1) {
            struct stat statistics;

            if (fstat(descriptor, &statistics) != -1) {
                printf("Размер файла %s: %ld", filename, statistics.st_size);
            }
            close(descriptor);
        }
    }

    return 0;
}

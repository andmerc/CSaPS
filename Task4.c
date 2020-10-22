#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Не хватает аргументов. Использование: program 'filename'");
    }
    else
    {
        char* filename = "filename"; // argv[1];
    
        struct stat statistics;

        if (stat(filename, &statistics) != -1) {
            printf("Размер файла %s: %ld", filename, statistics.st_size);
        }
    }

    return 0;
}

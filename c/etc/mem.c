#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BLOCK_SIZE 1024
#define DELAY      1e5

int main(void)
{
    pid_t id = getpid();
    char name_file[50];
    FILE *mem;

    sprintf(name_file, "/proc/%d/status", id);
    mem = fopen(name_file, "r");

    while (1) {
        malloc(BLOCK_SIZE);
        usleep(DELAY);
    }

    fclose(mem);
    return 0;
}

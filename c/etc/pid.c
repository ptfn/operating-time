#include <unistd.h>
#include <stdio.h>

int main(void)
{
    printf("%d\n%d\n", getpid(), getppid());
    return 0;
}

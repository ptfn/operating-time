#include <dirent.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *ent;

    dir = opendir(argv[1]);

    if (dir == NULL) {
        perror("Error");
        return 1;
    }
    
    while ((ent=readdir(dir)) != 0) {
            printf("%ld - %s [%d] %d\n", ent->d_ino, ent->d_name, ent->d_type, ent->d_reclen);
    }

    closedir(dir);

    return 0;
}

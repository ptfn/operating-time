#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>

int main()
{
    mpz_t sum, count;
    mpz_init(sum);

    char * filename = "13.txt";
    char cc[50];
    FILE *fp;

    if((fp= fopen(filename, "r"))==NULL) {
        perror("Error occured while opening file");
        return 1;
    }
    while((fgets(cc, 50, fp))!=NULL) {
        mpz_init_set_str(count, cc, 10);
        mpz_add(sum, sum, count);
        mpz_clear(count);
    }

    gmp_printf("%Zd\n", sum);
    fclose(fp);
}
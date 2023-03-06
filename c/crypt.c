#include <gcrypt.h>
#include <stdio.h>
#define L 100

int main(void)
{
    int algo = GCRY_MD_MD5;
    unsigned int l = gcry_md_get_algo_dlen(algo);
    unsigned char *x;
    unsigned i;

    char s[L];
    scanf("%s", s);

    gcry_md_hd_t h;
    gcry_md_open(&h, algo, GCRY_MD_FLAG_SECURE);
    gcry_md_write(h, s, strlen(s));
    x = gcry_md_read(h, algo);

    for (i = 0; i < l; i++) {
        printf("%02x", x[i]);
    }
    printf("\n");
    return 0;
}

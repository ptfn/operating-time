#include <stdint.h>
#include <stdio.h>
#include <gmp.h>

void gcd(mpz_t rop, mpz_t op1, mpz_t op2)
{
    mpz_t R, a, b;
    mpz_init(R);
    mpz_init_set(a, op1);
    mpz_init_set(b, op2);

    while (mpz_sgn(a) != 0 && mpz_sgn(b) != 0) {
        if (mpz_cmp(a, b) > 0) {
            mpz_mod(a, a, b);
        } else {
            mpz_mod(b, b, a);
        }
    }

    mpz_add(R, a, b);
    mpz_init_set(rop, R);
}

void carmichael(uint64_t number)
{
   mpz_t ipz, jpz, kpz, npz;
   uint64_t i, j;

   mpz_init_set_ui(ipz, 1);
   mpz_init_set_ui(jpz, 1);
   mpz_init_set_ui(npz, number);

   while (mpz_cmp(jpz, npz) < 0) {
        gcd(kpz, npz, jpz);

        if (mpz_cmp_ui(kpz, 1) == 0) {
            i = mpz_get_ui(ipz);
            j = mpz_get_ui(jpz);

            mpz_ui_pow_ui(kpz, j, i);
            mpz_mod_ui(kpz, kpz, number);

            if (mpz_cmp_ui(kpz, 1) != 0) {
                mpz_init_set_ui(jpz, 1);
                mpz_add_ui(ipz, ipz, 1);
            }
        }
        mpz_add_ui(jpz, jpz, 1);
   }
   gmp_printf("%Zd\n", ipz);
}

int main()
{
    carmichael(112169);
    return 0;
}
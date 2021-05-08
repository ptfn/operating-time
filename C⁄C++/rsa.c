#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int dres(int, int);

void main ()
{
    int p,q,n,e,f,d,c,m;

    p = 3557;
    q = 2579;
    n = p * q;
    f = (p - 1) * (q - 1);
    e = 3;
    c = 4051753;

    d = dres(e, f);
    printf("p = %d\nq = %d\nn = %d\nfe = %d\ne = %d\nd = %d\n",p, q, n, f, e, d);
    
    m = fmod(pow(c,d), n);
    printf("m = %d\n",m);
}    

int dres(int e, int f){
    int res, i;
    for(i = 0; i <= f; i++){
        res = (e * i) % f;
        if(res == 1) return i;
    }
}

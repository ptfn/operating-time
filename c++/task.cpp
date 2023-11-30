#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

int main()
{
    short a, b, aj, bj, as, bs;
    unsigned char c[4];
    
    cin >> a >> b;

    aj = *(char*)&a;
    as = *((char*)&a + 1);

    bj = *(char*)&b;
    bs = *((char*)&b + 1);

    memcpy(c, (char*)&as, sizeof(char));
    memcpy(c+1, (char*)&bs, sizeof(char));
    memcpy(c+2, (char*)&aj, sizeof(char));
    memcpy(c+3, (char*)&bj, sizeof(char));

    int d = (c[0] << 24) + (c[1] << 16) + (c[2] << 8) + c[3];    

    printf("%d\n", d); // Variable
    printf("%p\n", &d); // Adress 
    
    return 0;
}
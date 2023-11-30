#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

static const char dict[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
static char hex[] = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
static char base[] = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";

static uint8_t *hextostr(uint8_t *hex, size_t len)
{
    uint8_t *res = malloc(len / 2 * sizeof(uint8_t));

    for (size_t i = 0, j = 0; i < len; i += 2) {
        uint8_t ch1 = hex[i] > 96 ? hex[i] - 'a' + 10 : hex[i] - '0';
        uint8_t ch2 = hex[i+1] > 96 ? hex[i+1] - 'a' + 10 : hex[i+1] - '0';
        res[j++] = ch1 * 16 + ch2;
    }
    return res;
}

static uint8_t chtobase(uint8_t ch)
{
    for (size_t i = 0; i < 64; i++)
        if (ch == dict[i])
            return i;
    return 64;
}

uint8_t *base64_encode(uint8_t *str, size_t len)
{
    uint8_t *res = malloc((len/0.75)*sizeof(uint8_t));
    size_t i = 0, j = 0;

    while (i < len) {
        uint8_t ch1 = str[i++];
        uint8_t ch2 = i >= len ? 0 : str[i++];
        uint8_t ch3 = i >= len ? 0 : str[i++];

        uint8_t res1 = (ch1 >> 2) & 0xFF; 
        uint8_t res2 = ((ch1 << 6 & 0xFF) >> 2) | (ch2 >> 4);
        uint8_t res3 = ((ch2 << 4 & 0xFF) >> 2) | (ch3 >> 6);
        uint8_t res4 = (ch3 << 2 & 0xFF)  >> 2;

        res[j++] = dict[res1];
        res[j++] = dict[res2];
        res[j++] = ch2 ? dict[res3] : dict[64];
        res[j++] = ch3 ? dict[res4] : dict[64];
    
    return res;
}

uint8_t *base64_decode(uint8_t *str, size_t len)
{
    uint8_t *res = malloc(len*sizeof(uint8_t));
    size_t i = 0, j = 0;

    while (i < len) {
        uint8_t ch1 = chtobase(str[i++]);
        uint8_t ch2 = chtobase(str[i++]);        
        uint8_t ch3 = str[i] == '=' ? 0 : chtobase(str[i++]);
        uint8_t ch4 = str[i] == '=' ? 0 : chtobase(str[i++]);

        uint8_t res1 = (ch1 << 2) | (ch2 >> 4);
        uint8_t res2 = (ch2 << 4) | (ch3 >> 2);
        uint8_t res3 = (ch3 << 6) | ch4;

        res[j++] = res1;
        res[j++] = res2;
        res[j++] = res3;
    }
    return res;
}

int main(void)
{
    char *str = hextostr(hex, strlen(hex));

    char *res = base64_encode(str, strlen(str));
    char *res2 = base64_decode(res, strlen(res));

    puts(base);
    puts(res);
    puts(res2);

    return 0;
}

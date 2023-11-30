#include "sha256.h"
#include <stdint.h>

#define RR(N, M) (((N) >> (M)) | ((N) << (32 - (M))))
#define RL(N, M) (((N) << (M)) | ((N) >> (32 - (M))))

void sha256(uint8_t *initial_msg, size_t initial_len, uint8_t hash[])
{
    /* Init Const */
    uint32_t K[64] = {0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5, 0x3956C25B, 0x59F111F1, 0x923F82A4, 0xAB1C5ED5,
                      0xD807AA98, 0x12835B01, 0x243185BE, 0x550C7DC3, 0x72BE5D74, 0x80DEB1FE, 0x9BDC06A7, 0xC19BF174,
                      0xE49B69C1, 0xEFBE4786, 0x0FC19DC6, 0x240CA1CC, 0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA,
                      0x983E5152, 0xA831C66D, 0xB00327C8, 0xBF597FC7, 0xC6E00BF3, 0xD5A79147, 0x06CA6351, 0x14292967,
                      0x27B70A85, 0x2E1B2138, 0x4D2C6DFC, 0x53380D13, 0x650A7354, 0x766A0ABB, 0x81C2C92E, 0x92722C85,
                      0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3, 0xD192E819, 0xD6990624, 0xF40E3585, 0x106AA070,
                      0x19A4C116, 0x1E376C08, 0x2748774C, 0x34B0BCB5, 0x391C0CB3, 0x4ED8AA4A, 0x5B9CCA4F, 0x682E6FF3,
                      0x748F82EE, 0x78A5636F, 0x84C87814, 0x8CC70208, 0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2};
    
    /* Init Variables */
    uint32_t h0 = 0x6a09e667;    // A
    uint32_t h1 = 0xbb67ae85;    // B
    uint32_t h2 = 0x3c6ef372;    // C
    uint32_t h3 = 0xa54ff53a;    // D
    uint32_t h4 = 0x510e527f;    // E
    uint32_t h5 = 0x9b05688c;    // F
    uint32_t h6 = 0x1f83d9ab;    // G
    uint32_t h7 = 0x5be0cd19;    // H
    
    /* Changing And Modifying A Message */
    /*  uint8_t *msg = NULL;
    uint32_t new_len = ((((initial_len + 8) / 64) + 1) * 64) - 8;
 
    msg = calloc(new_len + 64, 1);
    memcpy(msg, initial_msg, initial_len);
    msg[initial_len] = 128;
 
    uint32_t bits_len = 8*initial_len;
    memcpy(msg + new_len, &bits_len, 4);
    */

    
    /* Main Loop */
    for(uint32_t offset = 0; offset < new_len; offset += (512/8)) {
        uint32_t W[64];

        for (uint32_t i = 16; i < 64; i++) {
            uint32_t s0 = RL(W[i-15], 7) ^ RL(W[i-15], 18) ^ RR(W[i-15], 3);
            uint32_t s1 = RL(W[i-2], 17) ^ RL(W[i-2], 19) ^ RR(W[i-2], 10);
            W[i] = W[i-16] + s0 + W[i-7] + s1;
        }
        
        uint32_t A, B, C, D, E, F, G, H;
        A = h0;
        B = h1;
        C = h2;
        D = h3;
        E = h4;
        F = h5;
        G = h6;
        H = h7;

        /* Function Loop */
        for (uint32_t i = 0; i < 64; i++) {
            uint32_t S0, S1, Ma, Ch, t1, t2;
            
            S0 = RL(A, 2) ^ RL(A, 13) ^ RL(A, 22);
            Ma = (A & B) ^ (A & C) ^ (B & C);
            t2 = S0 + Ma;
            S1 = RL(E, 6) ^ RL(E, 11) ^ RL(E, 25);
            Ch = (E & F) ^ ((~E) & G);
            t1 = H + S1 + Ch + K[i] + W[i];

            H = G;
            G = F;
            F = E;
            E = D + t1;
            D = C;
            C = B;
            B = A;
            A = t1 + t2;
        }
        h0 = h0 + A;
        h1 = h1 + B;
        h2 = h2 + C;
        h3 = h3 + D;
        h4 = h4 + E;
        h5 = h5 + F;
        h6 = h6 + G;
        h7 = h7 + H;

    }

    // free(msg);

    /* Build Hash */
    uint8_t *temp, array_end[8][9];
    uint32_t array_begin[8] = {h0, h1, h2, h3, h4, h5, h6, h7};

    for (int i = 0; i < 8; i++) {
        temp = (uint8_t*) & array_begin[i];
        sprintf((char*)array_end[i], "%2.2x%2.2x%2.2x%2.2x", temp[0], temp[1], temp[2], temp[3]);
    }

    sprintf((char*)hash, "%s%s%s%s%s%s%s%s", array_end[0], array_end[1],
                                             array_end[2], array_end[3], 
                                             array_end[4], array_end[5],
                                             array_end[6], array_end[7]);
}

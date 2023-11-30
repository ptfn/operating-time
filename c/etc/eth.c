#include <secp256k1.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <sha3.h>

static secp256k1_context *ctx = NULL;
static secp256k1_pubkey pubkey;
static sha3_context c;

void slice(uint8_t *str, uint8_t *buffer, size_t start, size_t end)
{
    size_t j = 0;
    for (size_t i = start; i <= end; ++i)
        buffer[j++] = str[i];
    buffer[j] = 0;
}

static void print_hex(uint8_t *data, size_t size)
{
    printf("0x");
    for (size_t i = 0; i < size; i++)
        printf("%02x", data[i]);
    printf("\n");
}

static void print_hash(const uint8_t *hash)
{
    printf("0x");
    for (size_t i = 12; i < 32; i++)
        printf("%02x", hash[i]);
    printf("\n");
}

int main()
{
    int return_result;
    const uint8_t *hash;
    unsigned char seckey[32];
    unsigned char compressed_pubkey[64];
    unsigned char uncompressed_pubkey[65];

    /* Secret Key */

    FILE *frand = fopen("/dev/urandom", "r");

    fread(seckey, 32, 1, frand);
    fclose(frand);

    /* Public Key */

    ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN | SECP256K1_CONTEXT_VERIFY);
    return_result = secp256k1_ec_pubkey_create(ctx, &pubkey, seckey);
    assert(return_result);

    size_t len = sizeof(uncompressed_pubkey);
    return_result = secp256k1_ec_pubkey_serialize(ctx, uncompressed_pubkey, &len, &pubkey, SECP256K1_EC_UNCOMPRESSED);
    assert(return_result);
    slice(uncompressed_pubkey, compressed_pubkey, 1, 65);

    /* Hash Keccak256 */

    sha3_Init256(&c);
    sha3_SetFlags(&c, SHA3_FLAGS_KECCAK);
    sha3_Update(&c, compressed_pubkey, 64);

    hash = sha3_Finalize(&c);

    /* Input Keys */
    printf("Private Key:\t");
    print_hex(seckey, sizeof(seckey));

    printf("Public Key:\t");
    print_hex(compressed_pubkey, sizeof(compressed_pubkey));

    printf("Addres:\t\t");
    print_hash(hash);

    return 0;
}

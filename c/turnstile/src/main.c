#include <openssl/obj_mac.h>
#include <openssl/crypto.h>
#include <openssl/ecdsa.h>
#include <openssl/sha.h>
#include <openssl/pem.h>
#include <openssl/bn.h>
#include <openssl/ec.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

void print(const char *title, uint32_t length, uint8_t *digest)
{
    printf("%s", title);
    for (uint32_t i = 0; i < length; i++)
        printf("%02x", digest[i]);
    putchar('\n');
}

// void generate() // add name file
// {
//     /* Variables */
//     EC_KEY *key = NULL;
//     FILE *pub_key_file, *priv_key_file;
//     int ret_error;

//     /* Generate secp256k1 key pair */
//     key = EC_KEY_new_by_curve_name(NID_secp256k1);
//     ret_error = EC_KEY_generate_key(key);
//     assert(ret_error);

//     /* PEM Save */
//     priv_key_file = fopen("sec.pem", "w");
//     ret_error = PEM_write_ECPrivateKey(priv_key_file, key, NULL, NULL, 0, NULL, NULL);
//     assert(ret_error);

//     pub_key_file = fopen("pub.pem", "w");
//     ret_error = PEM_write_EC_PUBKEY(pub_key_file, key);
//     assert(ret_error);

//     EC_KEY_free(key);
// }

// void read(EC_KEY *key)
// {
//     /* Variables */
//     FILE *pub_key_file, *priv_key_file;
//     int ret_error;

//     /* PEM Read */
//     priv_key_file = fopen("sec.pem", "r");
//     ret_error = PEM_read_ECPrivateKey(priv_key_file, key, NULL, NULL);
//     assert(ret_error);

//     pub_key_file = fopen("pub.pem", "r");
//     ret_error = PEM_read_EC_PUBKEY(pub_key_file, key, NULL, NULL);
//     assert(ret_error);

//     return key;
// }

int main(int argc, char *argv[])
{
    EC_KEY *key = NULL;
    int ret_error;
    BIGNUM   *priv_key;
    EC_POINT *pub_key;
    EC_GROUP *secp256k1_group;
    char *pub_key_char, *priv_key_char;

    const char *message = "31.08.2024";
    unsigned char buffer_digest[SHA256_DIGEST_LENGTH];
    uint8_t *digest;
    uint8_t *signature;
    uint32_t signature_len;
    FILE *pub_key_file, *priv_key_file;
    int verification;

    // /* Generate secp256k1 key pair */

    key = EC_KEY_new_by_curve_name(NID_secp256k1);
    ret_error = EC_KEY_generate_key(key);
    assert(ret_error);
    // read(key);

    /* Get private key */
    priv_key = (BIGNUM *)EC_KEY_get0_private_key(key);
    priv_key_char = BN_bn2hex(priv_key);

    /* Get public key */
    pub_key = (EC_POINT *)EC_KEY_get0_public_key(key);
    secp256k1_group = EC_GROUP_new_by_curve_name(NID_secp256k1);
    pub_key_char = EC_POINT_point2hex(secp256k1_group, pub_key, POINT_CONVERSION_COMPRESSED, NULL);
    EC_GROUP_free(secp256k1_group);

    /* Print Keys */
    printf("Pivate key: %s\n", priv_key_char);
    printf("Public key: %s\n", pub_key_char);

    /* Sign message */
    signature_len = ECDSA_size(key);
    signature = (uint8_t *)OPENSSL_malloc(signature_len);
    digest = SHA256((const unsigned char *)message, strlen(message), buffer_digest);
    ret_error = ECDSA_sign(0, (const uint8_t *)digest, SHA256_DIGEST_LENGTH, signature, &signature_len, key);

    /* Print Signature */
    print("Message SHA-256: ", SHA256_DIGEST_LENGTH, digest); 
    print("Signature: ", signature_len, signature);
    
    // Verify the signature
    verification = ECDSA_verify(0, digest, SHA256_DIGEST_LENGTH, signature, signature_len, key);

    if (verification == 1)
        printf("Verification successful\n");
    else
        printf("Verification NOT successful\n");

    /* Free ECKEY */
    EC_KEY_free(key);
    OPENSSL_free(signature);

    return 0;
}

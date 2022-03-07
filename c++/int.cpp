#include <iostream>
#include <climits>

int main() {
    using namespace std;

    short n_short = SHRT_MAX;
    int n_int = INT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    unsigned short n_ushort = USHRT_MAX;
    unsigned int n_uint = UINT_MAX;
    unsigned long n_ulong = ULONG_MAX;
    unsigned long long n_ullong = ULLONG_MAX;

    cout << "SHORT / USHORT\t" << sizeof(n_short) << "\tbytes" << endl;
    cout << "INT / UINT\t" << sizeof(n_int) << "\tbytes" << endl;
    cout << "LONG / ULONG\t" << sizeof(n_long) << "\tbytes" << endl;
    cout << "LLONG / ULLONG\t" << sizeof(n_llong) << "\tbytes" << endl;
    cout << endl;

    cout << "SHORT\t" << n_short << endl;
    cout << "INT\t" << n_int << endl;
    cout << "LONG\t" << n_long << endl;
    cout << "LLONG\t" << n_llong << endl;
    cout << endl;

    cout << "USHORT\t" << n_ushort << endl;
    cout << "UINT\t" << n_uint << endl;
    cout << "ULONG\t" << n_ulong << endl;
    cout << "ULLONG\t" << n_ullong << endl;

    return 0;
}
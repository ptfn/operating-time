#include <iostream>
#include <climits>

int main() {
    using namespace std;

    int n_char = CHAR_MAX;
    short n_short = SHRT_MAX;
    int n_int = INT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    int n_uchar = UCHAR_MAX;
    unsigned short n_ushort = USHRT_MAX;
    unsigned int n_uint = UINT_MAX;
    unsigned long n_ulong = ULONG_MAX;
    unsigned long long n_ullong = ULLONG_MAX;    

    cout << "CHAR\t\t" << sizeof(char) << "\tbytes" << endl;
    cout << "SHORT / USHORT\t" << sizeof(short) << "\tbytes" << endl;
    cout << "INT / UINT\t" << sizeof(int) << "\tbytes" << endl;
    cout << "LONG / ULONG\t" << sizeof(long) << "\tbytes" << endl;
    cout << "LLONG / ULLONG\t" << sizeof(long long) << "\tbytes" << endl;
    cout << endl;

    cout << "CHAR\t" << n_char << endl;
    cout << "SHORT\t" << n_short << endl;
    cout << "INT\t" << n_int << endl;
    cout << "LONG\t" << n_long << endl;
    cout << "LLONG\t" << n_llong << endl;
    cout << endl;

    cout << "UCHAR\t" << n_uchar << endl;
    cout << "USHORT\t" << n_ushort << endl;
    cout << "UINT\t" << n_uint << endl;
    cout << "ULONG\t" << n_ulong << endl;
    cout << "ULLONG\t" << n_ullong << endl;

    return 0;
}
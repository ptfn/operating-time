#include <iostream>
#include <cmath>

long int fac(int n) {
    long res = 0;
    if (n < 0) {
        return 0;
    } else {
        for (int i = 1; i <= n; i++) {
            res *= i;
        }   
    }
    return res;
}

long double pi(unsigned int n) {
    long double res = 0;
    for (int i = 0; i <= n; i++) {
        res += pow(-1, i) / (2 * i + 1);
    }
    return res * 4;
}

long double pi2(unsigned int n) {
    long double res = 0;
    for (int k = 0; k <= n ; k++) {
        res += (fac(6 * k) * (13591409 + 545140134 * k)) / (fac(3 * k) * pow(fac(k), 3) * pow(-640320, 3 * k));
    }
    res *= 1 / (426880 * sqrt(10005));
    return 1 / res;
}

int main() {
    unsigned int n;
    std::cin >> n;
    std::cout << pi(n) << "\n";
    // std::cout << pi2(n) << "\n";
    return 0;
}
#include <iostream>

int sum(int a, int b);
int square(int a);

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << sum(a, b) << "\n";
    std::cout << square(a) << "\n" << square(b) << "\n";
    return 0;
}

int sum(int a, int b) {
    return a + b;
}

int square(int a) {
    return a * a;
}
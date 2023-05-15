#include <iostream>

int main() {
    using namespace std;
    char ch;
    int ci;

    cout << "Enter a character: ";
    cin >> ch;
    ci = ch;
    cout << "\nHello! " << "You enter: ";
    cout.put(ch); 
    cout << "\nASCII code: " << ci << endl;
}
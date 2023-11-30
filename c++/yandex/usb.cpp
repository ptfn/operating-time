#include <iostream>

using namespace std;

int main()
{
    long n, m, result = 0;
    short c2, c5;
    bool a = false;
    
    cin >> n >> m >> c2 >> c5;

    while (1) {
        if (n >= m) break;
        
        if (m-n >= 5) {
            if (((n+1) < m || c2 > c5) && (c2*3 > 5 || c2 > c5)) {
                result += c5;
                n += 4;
            } else {
                result += c2;
                n += 1;
            }
        } else {
            if (((n+1) < m || c2 > c5) && (c2*3 > 5 || c2 > c5)) {
                result += c5;
                n += 4;
            } else {
                result += c2;
                n += 1;
            }
        }
    }

    cout << result;

    return 0;
}
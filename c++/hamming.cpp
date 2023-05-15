#include <iostream>
#include <cmath>

#define F1(n) floor(log2(n))

using namespace std;

int hammingWeight(int num)
{
    int i, j, len = F1(num), weight = 0;

    for (i = len; i >= 0; i--) {
        if (num >= (j = pow(2, i))) {
            weight++; num -= j;
        }
    }
    return weight;
}

int hammingDistance(int a, int b)
{
    string str_a = to_string(a);
    string str_b = to_string(b);
    int dist_count = 0;

    for (int i = 0; i < str_a.length(); i++) {
        if (str_a[i] != str_b[i]) {
            dist_count++;
        }
    }
    return dist_count;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << hammingWeight(a^b) << endl;
    cout << hammingDistance(a, b) << endl;
}
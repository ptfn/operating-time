#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    long id;
    long r;
    long s;
    vector <int> si;
} stud;

void swap(stud *s1, stud *s2) 
{
    stud temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int main()
{
    long n, k, r, s, temp;
    int p [k];
    stud sn[n];
    int sr[n];
    
    cin >> n >> k;

    for (long i = 0; i < k; i++) {
        cin >> temp;
        p.push_back(temp);
    }

    for (long i = 0; i < n; i++) {
        cin >> r >> s;
        sn[i].r = r;
        sn[i].s = s; 
        sn[i].id = i;

        for (long j = 0; j < sn[i].s; j++) {
            cin >> temp;
            sn[i].si.push_back(temp);
        } 
    }

    for (long i = 0; i < n-1; i++) {
        for (long j = 0; j < n-1; j++) {
            if (sn[j].r > sn[j+1].r)
                swap(sn[j], sn[j+1]);
        }
    }

    for (long i = 0; i < n; i++) {
        for (long j = 0; j < sn.s; j++) {
            if (p[sn.si[j]-1] > 0)
                sr[sn.id]
        }
    }

    return 0;
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include<stack>
#include <complex>
#include <string>
#include <bitset>
#include <stdio.h>
#include <string.h>
#include<fstream>
#include <iomanip>

using namespace std;
#define el    '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define all(v)  ((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 1e5 + 74, OO = 0x3f3f3f3f;
ll const MOD = 2000000011, BASE = 127;

ll power(ll x, ll y) {
    ll res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res % MOD;
}

ll leftShift(ll code, ll val) {
    return ((code * BASE) % MOD + val) % MOD;
}

ll addAt(ll code, ll idx, ll val) {
    return ((code + (power(BASE, idx)*val)%MOD) % MOD);
}

class ExtendToPalindrome {
public:
    void solve(istream &cin, ostream &cout) {
//        write("o.txt");
        string s;
        while (cin >> s) {
            ll hashCode = 0, hashRev = 0, k = 0;
            for (int i = s.size() - 1 , len = 0; i >= 0; i--,++len) {
                hashCode = leftShift(hashCode,s[i]);
                hashRev = addAt(hashRev, len , s[i]);
                if (hashCode == hashRev) {
                    k = i;
                }
            }
            cout << s;
            for (int i = k-1; i >= 0; i--)
                cout << s[i];
            cout << el;
        }
    }
};
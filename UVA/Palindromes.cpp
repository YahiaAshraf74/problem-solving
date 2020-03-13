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
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 1e5 + 74, OO = 0x3f3f3f3f;
const ll MOD = 2000000033, BASE = 131;
int k;
string s;

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

ll leftShift(ll code) {
    return (code * BASE) % MOD;
}

ll addAt(ll code, ll pos, ll val) {
    return (code + (power(BASE, pos) * val) % MOD) % MOD;
}

ll removeAt(ll code, ll pos, ll val) {
    return (code - ((power(BASE, pos) * val) % MOD)) % MOD;
}
ll const MODINV = power(BASE, MOD - 2);
ll rightShift(ll code) {
    return (code * MODINV) % MOD;
}

class Palindromes {
public:
    void solve(istream &cin, ostream &cout) {


    }
};
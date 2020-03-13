#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <complex>
#include <string>
#include <bitset>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <assert.h>

using namespace std;
#define el    '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 1e5 + 74, OO = 0x3f3f3f3f;
const ll MOD = (ll) 1e9 + 7;

ll power(ll x, ll y) {
    ll res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1; // y = y/2
        x = (x * x) % MOD;
    }
    return res % MOD;
}

class CDNAAlignment {
public:
    void solve(istream &cin, ostream &cout) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int a = 0, c = 0, g = 0, t = 0;
        for (char ch : s) {
            switch (ch) {
                case 'A':
                    ++a;
                    break;
                case 'C':
                    ++c;
                    break;
                case 'G':
                    ++g;
                    break;
                case 'T':
                    ++t;
                    break;
                default:
                    break;
            }
        }
        int mx = max(max(a,c),max(g,t));
        int cnt = (a==mx) + (c==mx) + (g==mx) + (t==mx);
        cout << power(cnt,n) << el;
    }
};
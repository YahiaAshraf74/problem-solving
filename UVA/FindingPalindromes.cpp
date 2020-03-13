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
const int N = 2e6 + 74, OO = 0x3f3f3f3f;

const int MOD = 666013 , MOD2 = 100007 , BASE = 73;
int n, pi[N], m;
char s[N];
map<pair<int, int>, int> mp;

pair<int, int> getHash(int len) {
    pair<int, int> ret;
    for (int i = 1; i <= len; ++i) {
        ret.first = (ret.first * BASE + s[i]) % MOD;
        ret.second = (ret.second * BASE + s[i]) % MOD2;
    }
    return ret;
}

class FindingPalindromes {
public:
    void solve(istream &cin, ostream &cout) {
        cin >> n;
        long long ans = 0;
        for (int t = 1; t <= n; ++t) {
            cin >> m >> s + 1;
            int k = 0;
            // KMP to make the failure table to get the repeated string 
            for (int i = 2; i <= m; ++i) {
                while (k > 0 && s[k + 1] != s[i])
                    k = pi[k];
                if (s[k + 1] == s[i])
                    ++k;
                pi[i] = k;
            }
            int repatedStr = m;
            if (m % (m - pi[m]) == 0) // get the length of the repeated string
                repatedStr = m - pi[m];
            pair<int, int> hashCode = getHash(repatedStr);
            ans = ans + mp[hashCode];
            ++mp[hashCode];
        }
        cout << (ans * 2) + n << '\n';
        clr(pi,0);
        mp.clear();
    }
};
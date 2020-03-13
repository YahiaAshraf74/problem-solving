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
const int N = 1e5 + 74, OO = 0x3f3f3f3f, MOD = 2000000011, BASE = 127, MOD2 = 2000000033, BASE2 = 131;

class DGoodSubstrings {
public:
    void solve(istream &cin, ostream &cout) {
        string s, isGood;
        int k;
        cin >> s >> isGood >> k;
        set<pair<int, int>> goodSubstrings;
        for (int i = 0; i < s.size(); i++) {
            ll cntBad = 0, sCode = 0, sCode2 = 0;
            for (int j = i; j < s.size(); j++) {
                if (isGood[s[j] - 'a'] == '0')
                    ++cntBad;
                sCode = (sCode + (((sCode * BASE) % MOD) + (s[j])) % MOD) % MOD;
                sCode2 = (sCode2 + (((sCode2 * BASE2) % MOD2) + (s[j])) % MOD2) % MOD2;
                if (cntBad <= k) {
                    goodSubstrings.insert({sCode, sCode2});
                }
            }
        }
        cout << goodSubstrings.size();
    }
};
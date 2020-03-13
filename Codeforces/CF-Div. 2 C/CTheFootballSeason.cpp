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

class CTheFootballSeason {
public:
    void solve(istream &cin, ostream &cout) {
        ll n, p;
        int w, d;
        cin >> n >> p >> w >> d;
        for (int y = 0; y <= w; ++y) {
            ll totalWins = (p - y * d);
            if (totalWins % w != 0 || totalWins < 0)
                continue;
            totalWins /= w;
            if (totalWins + y <= n) {
                cout << totalWins << ' ' << y << ' ' << n - totalWins - y << el;
                return;
            }
        }
        cout << -1 << el;
    }
};
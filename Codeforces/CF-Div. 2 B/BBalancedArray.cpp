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
#define el  '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define sz(a) (int)(a).size()
const long long N = (int) 2e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

class BBalancedArray {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            if ((n / 2) & 1) {
                cout << "NO\n";
                continue;
            }
            cout << "YES\n";
            for (int i = 0, j = 2; i < n / 2; i++, j += 2)
                cout << j << ' ';
            int j = 1;
            for (int i = 0; i < n / 2 - 1; i++, j += 2)
                cout << j << ' ';
            cout << (n / 2) + j << el;
        }
    }
};
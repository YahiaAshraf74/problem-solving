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
#include <numeric>
#include <assert.h>

using namespace std;
#define el  '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define sz(a) (int)(a).size()
const long long N = (int) 2e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

class CHiringStaff {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n, m, k;
        cin >> n >> m >> k;
        if (k == 1 && n - m == 0 && n == 2) {
            cout << "4\n1 2 3 4\n";
        } else if ((k == 1 && n - m <= 1) || (n == m)) {
            cout << k * 2 + 1 << el;
            for (int i = 0; i < k; i++) {
                cout << 1 << ' ';
            }
            cout << n << ' ';
            for (int i = 0; i < k - 1; i++) {
                cout << n + 1 << ' ';
            }
            if(k == 1)
                cout << 2*n-1;
            else
                cout << 2*n;
        } else {
            cout << k * 2 << el;
            for (int i = 0; i < k; i++) {
                cout << 1 << ' ';
            }
            cout << n << ' ';
            for (int i = 0; i < k - 1; i++) {
                cout << n + 1 << ' ';
            }
        }
    }
};
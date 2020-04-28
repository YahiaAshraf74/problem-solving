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
const long long N = 205, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

class CGameWithChips {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 0; i < k * 2; i++) {
            int x, y;
            cin >> x >> y;
        }
        cout << (n - 1) + (m - 1) + n * m - 1 << el;
        for (int i = 0; i < n - 1; i++)
            cout << "U";
        for (int i = 0; i < m - 1; i++)
            cout << "L";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m - 1; j++) {
                if (i % 2 == 0)
                    cout << "R";
                else
                    cout << "L";
            }
            if (i + 1 < n)
                cout << "D";
        }
        cout << el;
    }
};
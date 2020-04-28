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

int a[N];

class DCarousel {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            int n;
            cin >> n;
            bool isSame = false;
            for (int i = 1; i <= n; i++) {
                cin >> a[i];
                isSame |= a[i] == a[i - 1];
            }
            isSame |= a[1] == a[n];
            if (count(a + 1, a + n + 1, a[1]) == n) {
                cout << 1 << el;
                while (n--)
                    cout << 1 << ' ';
            } else if (n % 2 == 0 || isSame) {
                cout << 2 << el;
                if (n % 2 == 0) {
                    for (int i = 0; i < n; i++)
                        cout << (i % 2) + 1 << ' ';
                } else {
                    bool once = false;
                    for (int i = 1, j = -1; i <= n; i++) {
                        if ((i == n) && a[1] == a[n] && !once) {
                            cout << 1 << ' ';
                        } else if ((a[i] == a[i - 1]) && !once) {
                            cout << j + 1 << ' ';
                            once = true;
                        } else {
                            j = (j + 1) % 2;
                            cout << j + 1 << ' ';
                        }
                    }
                }
            } else {
                cout << 3 << el;
                for (int i = 0; i < n -1; i++)
                    cout << (i % 2) + 1 << ' ';
                cout << 3 << ' ';
            }
            cout << el;
        }
    }
};
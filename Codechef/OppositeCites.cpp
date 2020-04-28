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

class OppositeCites {
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
            for (int i = 0; i < n; i++)
                cin >> a[i];
            bool can = n % 2 == 0;
            for (int i = 0; i < n / 2; i++) {
                int j = n / 2 + i;
                if (a[i] == -1 && a[j] == -1) {
                    a[i] = a[j] = 1;
                } else if (a[i] == -1 && a[j] != -1) {
                    a[i] = a[j];
                } else if (a[i] != -1 && a[j] == -1) {
                    a[j] = a[i];
                } else if (a[i] != a[j]) {
                    can = false;
                    break;
                }
            }
            if (can) {
                cout << "YES\n";
                for (int i = 0; i < n; i++)
                    cout << a[i] << " \n"[i == n - 1];
            } else {
                cout << "NO\n";
            }
        }
    }
};
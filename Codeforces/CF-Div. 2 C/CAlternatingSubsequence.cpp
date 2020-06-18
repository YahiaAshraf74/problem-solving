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

class CAlternatingSubsequence {
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
            vector<int> v(n + 2);
            for (int i = 0; i < n; i++)
                cin >> v[i];
            int mx = v[0];
            ll sum = 0;
            for (int i = 0; i < n - 1; i++) {
                if (v[i] < 0 && v[i + 1] < 0) {
                    mx = max(mx, v[i]);
                } else if (v[i] > 0 && v[i + 1] > 0) {
                    mx = max(mx, v[i]);
                } else {
                    mx = max(mx, v[i]);
                    sum += (ll) mx;
                    mx = v[i + 1];
                }
            }
            mx = max(mx,v[n-1]);
            sum += (ll) mx;
            cout << sum << el;
        }
    }
};
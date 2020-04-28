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

class TheFunNumberSystem {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            int k;
            string s;
            ll n;
            cin >> k >> s >> n;
            reverse(s.begin(), s.end());
            string ans;
            ll mx = 0, mn = 0;
            for (int i = k - 1; i >= 0; --i) {
                if (s[i] == 'p') {
                    mx += (1LL << i);
                    ans.push_back('1');
                } else {
                    mn -= (1LL << i);
                    ans.push_back('0');
                }
            }
            if (n > mx || n < mn) {
                cout << "Impossible" << endl;
                continue;
            }
            ll diff = mx - n;
            for (int i = 0; i < k; ++i) {
                int j = k - i - 1;
                if ((1LL << j) <= diff) {
                    diff -= (1LL << j);
                    if (ans[i] == '1')
                        ans[i] = '0';
                    else
                        ans[i] = '1';
                }
            }
            for (int i = 0; i < k; i++)
                cout << ans[i];
            cout << el;
        }
    }
};
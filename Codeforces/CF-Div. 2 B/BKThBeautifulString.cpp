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

class BKThBeautifulString {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            int n, k;
            cin >> n >> k;
            k--;
            string s(n, 'a');
            for (int i = 1; i <= n - 1; i++) {
                if (k >= i) {
                    k -= i;
                } else {
                    s[n - i - 1] = 'b';
                    s[n - k - 1] = 'b';
                    break;
                }
            }
            cout << s << el;
        }
    }
};
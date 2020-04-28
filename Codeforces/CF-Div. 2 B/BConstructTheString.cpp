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

class BConstructTheString {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        int t;
        cin >> t;
        while (t--) {
            int n, a, b;
            cin >> n >> a >> b;
            string ans = "";
            int dif = a - b;
            int bb = 0;
            for (char c = 'a'; c <= 'z' && ans.size() != n && bb < b; c++,bb++) {
                ans.push_back(c);
            }
            while (dif-- > 0 && ans.size() != n)
                ans.push_back(ans.back());
            string res = ans;
            while (res.size() < n)
                res += ans;
            for (int i = 0; i < n; i++)
                cout << res[i];
            cout << el;
        }
    }
};
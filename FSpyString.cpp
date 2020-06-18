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

class FSpyString {
public:

    int getDiff(string &s, string &s2) {
        int cnt = 0;
        for (int i = 0; i < sz(s); i++) {
            if (s[i] != s2[i]) {
                ++cnt;
            }
        }
        return cnt;
    }

    void solve(istream &cin, ostream &cout) {
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            int n, m;
            cin >> n >> m;
            vector<string> s(n);
            for (int i = 0; i < n; i++) {
                cin >> s[i];
            }
            if (n == 1) {
                cout << s[0] << el;
                continue;
            }
            string candidate = s[0], candidate2 = s[1];
            int diff = 0, mxDiff = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    diff = getDiff(s[i], s[j]);
                    if (diff > mxDiff) {
                        candidate = s[i], candidate2 = s[j];
                        mxDiff = diff;
                    }
                }
            }
            for (int i = 0; i < m; i++) {
                if (candidate[i] != candidate2[i]) {
                    swap(candidate[i], candidate2[i]);
                    break;
                }
            }
            for (int i = 0; i < n; i++) {
                if (getDiff(candidate, s[i]) > 1) {
                    candidate = "-1";
                }
                if (getDiff(candidate2, s[i]) > 1) {
                    candidate2 = "-1";
                }
            }
            cout << ((candidate == "-1" && candidate2 == "-1") ? "-1" : (candidate != "-1") ? candidate : candidate2) << el;
        }
    }
};
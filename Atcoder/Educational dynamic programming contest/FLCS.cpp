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
const long long N = (int) 3e3 + 2, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

string s, t, ans;
int mem[N][N];

class FLCS {
public:
    void init() {
        clr(mem, -1);
        ans.clear();
    }

    int solve(int i, int j) {
        if (i == sz(s) || j == sz(t))
            return 0;
        int &ret = mem[i][j];
        if (~ret)
            return ret;
        if (s[i] == t[j])
            return ret = solve(i + 1, j + 1) + 1;
        int ch1 = solve(i + 1, j);
        int ch2 = solve(i, j + 1);
        return ret = max(ch1, ch2);
    }

    void build(int i, int j) {
        if (i == sz(s) || j == sz(t))
            return;
        if (s[i] == t[j]) {
            ans.push_back(s[i]);
            build(i + 1, j + 1);
            return;
        }
        int ch1 = solve(i + 1, j);
        int ch2 = solve(i, j + 1);
        if (ch1 > ch2)
            build(i + 1, j);
        else
            build(i, j + 1);
    }

    void solve(istream &cin, ostream &cout) {
        init();
        cin >> s >> t;
        solve(0, 0);
        build(0, 0);
        cout << ans << el;
    }
};
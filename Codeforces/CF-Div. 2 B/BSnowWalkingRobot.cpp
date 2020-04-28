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

class BSnowWalkingRobot {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            string s;
            cin >> s;
            map<char, int> mp;
            for (char c : s)
                mp[c]++;
            if ((mp['L'] == 0 && mp['U'] && mp['D']) || (mp['R'] == 0 && mp['U'] && mp['D'])) {
                cout << 2 << el << "UD" << el;
            } else if ((mp['U'] == 0 && mp['R'] && mp['L']) || (mp['D'] == 0 && mp['R'] && mp['L'])) {
                cout << 2 << el << "RL" << el;
            } else if ((mp['U'] == 0 && mp['L'] == 0) || (mp['U'] == 0 && mp['R'] == 0) ||
                       (mp['D'] == 0 && mp['L'] == 0) || (mp['D'] == 0 && mp['R'] == 0)) {
                cout << 0 << el << el;
            } else {
                int v = min(mp['U'], mp['D']);
                int h = min(mp['L'], mp['R']);
                string ans = "U";
                ans += string(h, 'R') + string(v, 'D') + string(h, 'L') + string(v - 1, 'U');
                cout << sz(ans) << el;
                cout << ans << el;
            }
        }
    }
};
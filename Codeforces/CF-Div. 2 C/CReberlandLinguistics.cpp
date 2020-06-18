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

class CReberlandLinguistics {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        string s;
        cin >> s;
        set<string> st;
        for (int i = sz(s) - 2; i > 4; i--) {
            int rem = sz(s) - (i + 2);
            string t = s.substr(i,2);//s[i] + s[i + 1] + s[i + 2]);
            if (rem % 2 == 0 || rem % 3 == 0 || ((rem-2)%3 == 0&&rem-2>=0) || ( (rem-3)%2 == 0&& rem-3>=0) )
                st.insert(t);
        }
        for (int i = sz(s) - 3; i > 4; i--) {
            int rem = sz(s) - (i + 3);
            string t = s.substr(i,3);//s[i] + s[i + 1] + s[i + 2]);
            if (rem % 2 == 0 || rem % 3 == 0 || ((rem-2)%3 == 0&&rem-2>=0) || ( (rem-3)%2 == 0&& rem-3>=0) )
                st.insert(t);
        }
        cout << sz(st) << el;
        for (auto str : st) {
            cout << str << el;
        }
    }
};
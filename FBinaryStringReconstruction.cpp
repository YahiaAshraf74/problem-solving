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
#define clr(a,b)memset(a,b,sizeof(a))
#define sz(a) (int)(a).size()
const long long N = (int)2e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

class FBinaryStringReconstruction {
public:
	void solve(istream& cin, ostream& cout) {
        int t;
        cin >> t;
        while (t--) {
            int n0, n1, n2;
            cin >> n0 >> n1 >> n2;
            if (n1 == 0) {
                if (n0 != 0) {
                    cout << string(n0 + 1, '0') << el;
                } else {
                    cout << string(n2 + 1, '1') << el;
                }
                continue;
            }
            string ans;
            for (int i = 0; i < n1 + 1; ++i) {
                if (i & 1)
                    ans += "0";
                else
                    ans += "1";
            }
            ans.insert(1, string(n0, '0'));
            ans.insert(0, string(n2, '1'));
            cout << ans << el;
        }
	}
};
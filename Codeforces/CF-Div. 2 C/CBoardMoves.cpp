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

class CBoardMoves {
public:
    void init(){

    }

	void solve(istream& cin, ostream& cout) {
        init();
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            unsigned ll n;
            cin >> n;
            if(n == 1){
                cout << 0 << el;
                continue;
            }
            unsigned ll ans = 8 , cur = 16;
            for(int steps = 2;steps<=n/2;steps++){
                ans += steps * cur;
                cur+=8;
            }
            cout << ans << el;
        }
	}
};
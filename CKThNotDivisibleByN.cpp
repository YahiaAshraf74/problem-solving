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

class CKThNotDivisibleByN {
public:
    void solve(istream &cin, ostream &cout) {
        //Before touch the keyboard, think one minute on the big picture of the code.
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            ll n, k;
            cin >> n >> k;
            ll st = k, ed = (ll)2e18;
            ll ans = (ll)2e18;
            while(st < ed){
                ll mid = (ed+st) / 2;
                if(mid >= (mid/n) + k){
                    ans = mid;
                    ed = mid;
                }else{
                    st = mid+1;
                }
            }
            cout << ans << el;
        }
    }
};
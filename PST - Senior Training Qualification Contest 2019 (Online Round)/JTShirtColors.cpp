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
#define el    '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 1e5 + 74, OO = 0x3f3f3f3f;
const ll MOD = (ll)1e9 + 7;
ll power(ll x,ll y) {
    ll res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res%MOD;
}

class JTShirtColors {
public:
    void solve(istream &cin, ostream &cout) {
        ll n , m , k;
        cin >> n >> m >> k;
        if(m < n){
            cout << 0 <<el;
        }else{
            ll fact = 1;
            for(ll i = m ,j = 0;j<n&& i>=1;i--,j++){
                fact = ((fact%MOD) * (i%MOD))%MOD;
            }
            ll ans = ((fact%MOD)*(power(k,n)%MOD))%MOD;
            cout << ans << el;
        }
    }
};
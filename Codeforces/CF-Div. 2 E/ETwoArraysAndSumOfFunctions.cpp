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
#define el	'\n'
#define ll long long
#define clr(a,b)memset(a,b,sizeof(a))
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 2e5 + 74, OO = 0x3f3f3f3f;
const ll MOD = 998244353 ;

ll a[N] , b[N];
class ETwoArraysAndSumOfFunctions {
public:
	void solve(istream& cin, ostream& cout) {
        int n;
        cin >> n;
        for(ll i =0;i<n;i++){
            cin >> a[i];
            a[i] *= (n-i)*(i+1);
        }
        sort(a,a+n);
        for(int i =0;i<n;i++){
            cin >> b[i];
        }
        sort(b,b+n,[&](ll a,ll b){
            return a > b;
        });
        ll ans = 0;
        for(int i =0;i<n;i++){
            ans += (a[i]%MOD*b[i])%MOD;
            ans %= MOD;
        }
        cout << ans << el;
	}
};
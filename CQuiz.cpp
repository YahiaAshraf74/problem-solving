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
const int N = 1e5 + 74, OO = 0x3f3f3f3f;
const int MOD = (int)1e9+9;

ll power(ll x, ll y) {
    ll res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res % MOD;
}
class CQuiz {
public:
	void solve(istream& cin, ostream& cout) {
        int n , m , k;
        cin >> n >> m >> k;
        if(n-m >= n/k){
            cout << m << el;
            return;
        }
        int d = max(n / k - (n-m),0);
        int ans = (((power(2,d+1)-2+MOD)%MOD)*k)%MOD;
        cout << (ans + (m-d*k))%MOD;
	}
};
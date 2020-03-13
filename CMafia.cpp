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

class CMafia {
public:
	void solve(istream& cin, ostream& cout) {
        ll n;
        cin >> n;
        vector<ll> v(n);
        ll mn = OO ,mx = 0;
        for(ll &x : v) {
            cin >> x;
            mn = min(mn,x);
            mx = max(mx,x);
        }
        bool fm = false;
        ll mn2 = mn;
        for(ll &x : v){
            if(x == mn && !fm){
                fm = true;
                continue;
            }
            mn2 -= mx-x;
        }
        if(mn2 <= 0){
            cout << mx << el;
        }else{
            cout << mx + (ll)ceil((long double)mn2 / (n-1)) << el;
        }
	}
};
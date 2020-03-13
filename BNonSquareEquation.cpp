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

ll f(ll m){
    ll ans = 0;
    while(m){
        ans += m % 10;
        m /= 10;
    }
    return ans;
}
ll n;
bool can(ll m){
    return (((ll)m*m) + (ll)f(m)*m) - n == 0;
}
class BNonSquareEquation {
public:
	void solve(istream& cin, ostream& cout) {
	    write("o.txt");
        cin >> n;
        int ans = -1;
        for(ll i =0;i<=(int)1e6;i++){
//            if(can(i)){
//                ans = i;
//                break;
//            }
            ll p = ((ll)i*i)+((ll)f(i)*i);
            cout << p << el;
        }
//        cout << ans << el;
	}
};
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include<stack>
#include <complex>
#include <string>
#include <bitset>
#include <stdio.h>
#include <string.h>
#include<fstream>
#include <iomanip> 
using namespace std;
#define el	'\n'
#define ll long long
#define clr(a,b)memset(a,b,sizeof(a))
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

set<ll,greater<ll>> b;
class BKillEmAll {
public:
	void solve(istream& cin, ostream& cout) {
        int t;
        cin >> t;
        while(t--){
            ll n;
            ll r;
            cin >> n >> r;
            ll r2 = r;
            for (int i = 0; i < n; ++i) {
                ll x;
                cin >> x;
                b.insert(x);
            }
            bool first = true;
            int cnt = 1;
            for(auto it : b){
                if(first){
                    first = false;
                    continue;
                }
                if(it - r <= 0){
                    break;
                }else{
                    ++cnt;
                    r +=r2;
                }
            }
            cout << cnt << el;
            b.clear();
        }
	}
};
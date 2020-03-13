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
const int N = 3e5 + 74, OO = 0x3f3f3f3f;

ll a[N];
ll f[1005];
vector<pair<ll,ll>> v;
class HBekhTheCowEngineer {
public:
	void solve(istream& cin, ostream& cout) {
        ll n , k;
        cin >> n >> k;
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
            f[a[i]]++;
        }
        for(ll i = 1;i<=1000;i++){
            if(f[i] > 0){
                if(f[i] > 1)
                    v.push_back({i*i,(f[i]*(f[i]-1)/2)});
                for(ll j = i+1;j<=1000;j++){
                    if(f[j] > 0){
                        v.push_back({i*j,f[i]*f[j]});
                    }
                }
            }
        }
        sort(all(v),[&](pair<ll,ll> a, pair<ll,ll> b){
            return a.first > b.first;
        });
        ll i = 0;
        ll ans = 0;
        while(k>0){
            if(k - v[i].second >= 0){
                ans += v[i].first * v[i].second;
                k -= v[i].second;
            }else{
                ans += v[i].first * k;
                break;
            }
            i++;
        }
        cout << ans << el;
        clr(f,0);
        v.clear();
	}
};
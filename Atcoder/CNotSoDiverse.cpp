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
#define el  '\n'
#define ll long long
#define clr(a,b)memset(a,b,sizeof(a))
#define sz(a) (int)(a).size()
const long long N = 2e5 + 74, OO = 0x3f3f3f3f, MOD = (long long) 1e9 + 7;

int a[N];
class CNotSoDiverse {
public:
	void solve(istream& cin, ostream& cout) {
        int n ,k;
        cin >> n>> k;
        set<int> st;
        vector<pair<int,int>> v(n+1);
        for(int i= 0;i<n;i++){
            cin >> a[i];
            st.insert(a[i]);
            v[a[i]].second++;
            v[a[i]].first = a[i];
        }
        if(sz(st) <= k){
            cout << 0 << el;
        }else{
            sort(v.begin(), v.end(),[&](pair<int,int> a, pair<int,int> b){
               return a.second < b.second;
            });
            int need = sz(st) - k;
            int ans = 0;
            for(int i = 0;i<sz(v) && need > 0;i++){
                if(v[i].second == 0)
                    continue;
                need--;
                ans += v[i].second;
            }
            cout << ans << el;
        }
	}
};
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
#define clr(a, b)memset(a,b,sizeof(a))
#define sz(a) (int)(a).size()
const long long N = (int) 2e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

class CTwoTeamsComposing {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            vector<int> v;
            map<int, int> mp;
            for (int i = 0; i < n; i++) {
                int x;
                cin >> x;
                v.push_back(x);
                mp[x]++;
            }
            int mx = 0;
            for (auto it : mp) {
                mx = max(it.second, mx);
            }
            int m = mp.size() - 1;
            if(m >= mx && mx * 2 <= n){
                cout << mx << el;
                continue;
            }
            ++m , mx--;
            if(m >= mx && mx*2<=n){
                cout << mx << el;
            }else{
                cout << min(m,mx) << el;
            }
            
        }
    }
};
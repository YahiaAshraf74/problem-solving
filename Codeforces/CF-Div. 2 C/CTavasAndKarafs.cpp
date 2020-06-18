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
const long long N = (int) 2e6 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

class CTavasAndKarafs {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        int a, b, n;
        cin >> a >> b >> n;
        vector<ll> v(N), cum(N);
        for (int i = 1; i < N; i++) {
            v[i] = (ll) a + (ll)(i - 1) * b;
            cum[i] = cum[i - 1] + v[i];
        }
        while(n--){
            int l , t ,m;
            cin >> l >> t >> m;
            int st = l , ed = N - 1 , ans = -1;
            while(st <= ed){
                int mid = st + (ed-st)/2;
                ll sum = cum[mid] - cum[l-1];
                if(sum <= (ll)m * t && v[mid] <= t){
                    st = mid + 1;
                    ans = mid;
                }else{
                    ed = mid - 1;
                }
            }
            cout << ans << el;
        }
    }
};
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

int a[N] , b[N] , idx[N];
class CStackOfPresents {
public:
	void solve(istream& cin, ostream& cout) {
	    int t;
	    cin >> t;
	    while(t--) {
            int n, m;
            cin >> n >> m;
            for (int i = 1; i <= n; i++) {
                cin >> a[i];
                idx[a[i]] = i;
            }
            int last = 0, remove = 0;
            ll ans = 0;
            for (int i = 1; i <= m; i++) {
                cin >> b[i];
                if (idx[b[i]] <= last) {
                    ans++;
                    remove++;
                } else {
                    ll cost = max(1,idx[b[i]] - remove);
                    ans += max((ll)1,cost + cost-1);
                    last = idx[b[i]];
                    remove++;
                }
            }
            cout << ans << el;
        }
	}
};
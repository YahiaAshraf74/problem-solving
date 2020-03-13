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
const int N = 1e3 + 74, OO = 0x3f3f3f3f;

int a[N], cnt[N], cum[N];
class CPlatformsJumping {
public:
	void solve(istream& cin, ostream& cout) {
        int n, m, d;
        cin >> n >> m >> d;
        for(int i = 0 ; i < m ; ++i)
            cin >> a[i];
        for(int i = m - 1 ; i != -1 ; --i)
            cnt[i] = a[i] + cnt[i + 1];
        int i = 0;
        for(int j = 0; j < m && i <= n ; ++j){
            int idx = min(n - cnt[j] + 1, i + d);
            ++cum[idx];
            i = idx + a[j] - 1;
            --cum[i + 1];
        }
        if(i + d <= n){
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        int hna = 1;
        int here = 0;
        for(int i = 1 , j = 0; i <= n ; ++i){
            cum[i] += cum[i - 1];
            if(cum[i]){
                if(a[j] == here)
                    ++j, ++hna, here = 0;
                cout << hna << ' ';
                ++here;
                continue;
            }
            cout << 0 << ' ';
        }
        cout << el;
	}
};
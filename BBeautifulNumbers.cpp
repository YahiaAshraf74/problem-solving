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
const int N = 2e5 + 74, OO = 0x3f3f3f3f;

int a[N];
int ans[N];
class BBeautifulNumbers {
public:
	void solve(istream& cin, ostream& cout) {
        int t;
        cin >> t;
        while(t--){
            int n;
            cin >> n;
            int one = 0;
            for (int i = 1; i <= n; ++i) {
                cin >> a[i];
                if(a[i] == 1)
                    one = i;
            }
            int mx = 1;
            for(int sz = 2,i=one,j=one;sz<=n;sz++){
                if(j==n ||(i-1 >=1 && a[i-1] < a[j+1]))
                    --i;
                else if(i==1 || (j+1 <=n && a[i-1] > a[j+1]))
                    ++j;
                else {
                    assert(true);
                }
                mx = max(mx,max(a[i],a[j]));
                if(sz == mx){
                    ans[sz] = 1;
                }
            }
            ans[1] = 1;
            for(int i =1;i<=n;i++){
                cout << ans[i];
                ans[i] = 0;
            }
            cout << el;
        }
	}
};
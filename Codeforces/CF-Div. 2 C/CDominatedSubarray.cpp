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
class CDominatedSubarray {
public:
	void solve(istream& cin, ostream& cout) {
        int t;
        cin >> t;
        while(t--){
            int n;
            cin >> n;
            int mx =0 ;
            for(int i=1;i<=n;i++){
               cin >> a[i];
               mx = max(mx,a[i]);
            }
            vector<int> idx(mx+2);
            int ans = OO;
            for(int i =1;i<=n;i++){
                if(idx[a[i]] == 0){
                    idx[a[i]] = i;
                }else{
                    ans = min(ans,i-idx[a[i]]+1);
                    idx[a[i]] = i;
                }
            }
            if(ans == OO)
                cout << -1 << el;
            else
                cout << ans << el;
        }
	}
};
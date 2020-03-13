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

int f[32];
class EXor {
public:
	void solve(istream& cin, ostream& cout) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            int j = 0;
            while(x){
                if(x&1){
                    f[j]++;
                }
                x >>= 1;
                j++;
            }
        }
        ll ans = 0;
        for(int i = 0;i<=30;i++){
            if(f[i] == 0){
                continue;
            }else{
                if(f[i] <= n-f[i]+1 ){
                    ans += (ll)f[i];
                }else{
                    ans += (ll)n-f[i]+1;
                }
            }
        }
        cout << ans << el;
	}
};
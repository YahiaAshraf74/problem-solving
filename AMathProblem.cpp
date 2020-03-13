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

pair<int,int> a[N];
class AMathProblem {
public:
	void solve(istream& cin, ostream& cout) {
        int t;
        cin >> t;
        while(t--){
            int n;
            cin >> n;
            int mn = OO , mx = 0;
            for(int i =0;i<n;i++){
                int l , r;
                cin >> l >> r;
                mn = min(mn,r);
                mx = max(mx,l);
            }
            if(n==1){
                cout << 0 << el;
                continue;
            }
            if(mn >= mx){
                cout << 0 <<el;
            }else{
                cout << mx - mn << el;
            }
        }
	}
};
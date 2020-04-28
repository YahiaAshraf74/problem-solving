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
const long long N = (int)1e5 + 2, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

int a[N];
ll tree[N*4] , lazy[N*4];
class HorribleQueries {
public:
    void init(int n){
        memset(tree,0,sizeof(tree[0])*n*4+1);
        memset(lazy,0,sizeof(lazy[0])*n*4+1);
    }
    void updateRange(int n,int st,int ed,int l ,int r,int val){
        if(lazy[n] != 0){
            tree[n] += (ll)(ed-st+1) * lazy[n];
            if(st != ed)
                lazy[n*2+1] += lazy[n] , lazy[n*2+2] += lazy[n];
            lazy[n] = 0;
        }
        if(ed < l || st > r)
            return;
        else if(st >= l && ed <= r){
            tree[n] += (ll)(ed-st+1) * val;
            if(st != ed)
                lazy[n*2+1] += val , lazy[n*2+2] += val;
        }else{
            int mid = (st+ed) >> 1;
            updateRange(n*2+1,st,mid,l,r,val);
            updateRange(n*2+2,mid+1,ed,l,r,val);
            tree[n] = tree[n*2+1] + tree[n*2+2];
        }
    }
    ll quaryRange(int n,int st,int ed,int l, int r){
        if(lazy[n] != 0){
            tree[n] += (ll)(ed-st+1) * lazy[n];
            if(st != ed)
                lazy[n*2+1] += lazy[n] , lazy[n*2+2] += lazy[n];
            lazy[n] = 0;
        }
        if(ed < l || st > r)
            return 0;
        else if(st >= l && ed <= r){
            return tree[n];
        }else{
            int mid = (st+ed) >> 1;
            return quaryRange(n*2+1,st,mid,l,r) + quaryRange(n*2+2,mid+1,ed,l,r);
        }
    }
	void solve(istream& cin, ostream& cout) {
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            int n ,q;
            cin >> n >> q;
            init(n);
            while(q--){
                int type , l , r;
                cin >> type >> l >> r;
                if(type == 0){
                    int  val;
                    cin >> val;
                    updateRange(0,0,n-1,l-1,r-1,val);
                }else{
                    cout << quaryRange(0,0,n-1,l-1,r-1) << el;
                }
            }
        }

	}
};
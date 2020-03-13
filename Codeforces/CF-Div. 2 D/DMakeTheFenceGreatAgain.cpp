#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include<stack>
#include <complex>
#include <string>
#include <bitset>
#include <stdio.h>
#include <string.h>
#include<fstream>
using namespace std;
#define el	'\n'
#define ll long long
#define clr(a,b)memset(a,b,sizeof(a))
#define all(v)  ((v).begin()),((v).end())
const int N = 3e5 + 74;
const ll OO = (ll)1e18+100;

int n;
ll mem[N][3];
pair<int,int> v[N];
ll dp(int i,int plus,int pre){
    if(i > n)
        return 0;
    ll &ret = mem[i][plus];
    if(~ret)
        return ret;
    ll ch1 = OO , ch2 = OO , ch3 = OO , ch4 = OO;
    if(v[i].first == pre){
        ch1 = dp(i+1,1,v[i].first+1) + v[i].second;
        ch2 = dp(i+1,2,v[i].first+2) + v[i].second + v[i].second;
//        ch3 = dp(i+1,3,v[i].first+3) + v[i].second + v[i].second+ v[i].second;
    }else{
        if(v[i].first+1 != pre)
          ch1 = dp(i+1,1,v[i].first+1) + v[i].second;
        if(v[i].first+2 != pre)
            ch2 = dp(i+1,2,v[i].first+2) + v[i].second + v[i].second;
//        if(v[i].first+3 != pre)
//            ch3 = dp(i+1,3,v[i].first+3) + v[i].second + v[i].second+ v[i].second;
        ch4 = dp(i+1,0,v[i].first);
    }
    return ret = min(min(ch1,ch2),min(ch3,ch4));
}
class DMakeTheFenceGreatAgain {
public:
	void solve(istream& cin, ostream& cout) {
        int q;
        cin >> q;
        while(q--){
            cin >> n;
            for(int i=1;i<=n;i++){
                cin >> v[i].first >> v[i].second;
                for(int j=0;j<=2;j++)
                    mem[i][j] = -1;
            }
            ll ans = dp(1,0,-1);
            cout << ans << el;
        }
	}
};
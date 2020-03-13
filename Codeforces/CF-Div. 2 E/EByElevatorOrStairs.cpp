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
#include <iomanip> 
using namespace std;
#define el	'\n'
#define ll long long
#define clr(a,b)memset(a,b,sizeof(a))
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 2e5 + 5, OO = 0x3f3f3f3f;

int mem[N][2];
int n , c;
int a[N] , b[N];
int dp(int i,bool cc){
    if(i == 0){
        return 0;
    }
    int &ret = mem[i][cc];
    if(~ret)
        return ret;
    ret = 0;
    if(cc == 0){
        ret = min(dp(i-1,0)+a[i],dp(i-1,1)+b[i]+c);
    }else{
        ret = min(dp(i-1,1)+b[i],dp(i-1,0)+a[i]);
    }
    return ret;
}
class EByElevatorOrStairs {
public:
	void solve(istream& cin, ostream& cout) {
        cin >> n >> c;
        for (int i = 1; i <= n-1; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n-1; ++i) {
            cin >> b[i];
        }
        clr(mem,-1);
        for(int i =0;i<n;i++){
            cout << dp(i,0) << ' ';
        }
	}
};
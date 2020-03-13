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
#define all(v)  ((v).begin()),((v).end())
const int N = 1e2 + 2, OO = 0x3f3f3f3f , MOD = (int)1e8;

int n1,n2,k1,k2;
int mem[N][N][11][11];
int dp(int m1, int m2 , int c1,int c2){
    if(m1+m2 == 0)
        return 1;
    int &ret = mem[m1][m2][c1][c2];
    if(~ret)
        return ret;
    ret = 0;
    if(m1 - 1 >= 0 && c1 + 1 <= k1){
        ret += dp(m1-1,m2,c1+1,0)%MOD;
    }
    if(m2 - 1 >= 0 && c2 +1 <=k2){
        ret += dp(m1,m2-1,0,c2+1)%MOD;
    }
    return ret%MOD;
}
class DCaesarsLegions {
public:
	void solve(istream& cin, ostream& cout) {
        cin >> n1 >> n2 >> k1 >> k2;
        clr(mem,-1);
        int res = dp(n1,n2,0,0);
        cout << res << el;
	}
};
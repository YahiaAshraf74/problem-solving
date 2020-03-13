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
const int N = 1e5 + 74, OO = 0x3f3f3f3f , MOD = (int)1e9 + 7;

int n , k ,d;
int mem[102][102];
int dp(int sum,int mx){
    if(sum < 0){
        return 0;
    }
    if(sum == 0 && mx >= d){
        return 1;
    }
    int &ret = mem[sum][mx];
    if(~ret)
        return ret;
    ret = 0;
    for(int j = 1;j<=k;j++){
        ret += dp(sum-j,max(mx,j));
        ret %=MOD;
    }
    return ret;
}
class CKTree {
public:
	void solve(istream& cin, ostream& cout) {
        cin >> n >> k >> d;
        clr(mem,-1);
        int res = dp(n,0);
        cout << res%MOD ;
	}
};
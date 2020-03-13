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
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

int dp[N][2];
class JThanosPower {
public:
	void solve(istream& cin, ostream& cout) {
        string s;
        cin >> s;
        dp[0][0] = 10 - (s[0]-'0') + 1;
        dp[0][1] = s[0]-'0';
        for (int i = 1; i < (int) s.size(); ++i) {
            dp[i][0] = 10 - (s[i]-'0') + min(dp[i-1][0]-1,dp[i-1][1] + 1);
            dp[i][1] = s[i]-'0' + min(dp[i-1][0],dp[i-1][1]);
        }
        int ans = min(dp[(int)s.size()-1][0],dp[(int)s.size()-1][1]);
        cout << ans << el;
	}
};
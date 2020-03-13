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
#define el    '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define all(v)  ((v).begin()),((v).end())
const int N = 203, OO = 0x3f3f3f3f;

pair<int, int> b[N];
long double dp[N][N];

long double dist(pair<int, int> f, pair<int, int> t) {
    return sqrt((f.first - t.first) * (f.first - t.first) + (f.second - t.second) * (f.second - t.second));
}
class Frogger {
public:
    void solve(istream &cin, ostream &cout) {
        //freopen("o.txt","w",stdout);
        int n;
        int testCases = 0;
        while (cin >> n) {
            if (!n)
                break;
            for (int i = 0; i < n; i++) {
                cin >> b[i].first >> b[i].second;
                for (int j = 0; j < n; j++)
                    dp[i][j] = 1e9;
                dp[i][i] = 0.0;
            }
            for(int i =0;i<n;i++){
                for(int j = i + 1;j<n;j++){
                    dp[i][j] = dp[j][i] = dist(b[i], b[j]);
                }
            }
            for(int k = 0;k<n;k++){
                for(int i = 0;i<n;i++){
                    for(int j =0;j<n;j++){
                        dp[i][j] = min(dp[i][j],max(dp[i][k],dp[k][j]));
                    }
                }
            }
            cout << "Scenario #" << ++testCases << el;
            cout <<fixed<< setprecision(3) <<"Frog Distance = " << dp[0][1] << el << el;
        }
    }
};
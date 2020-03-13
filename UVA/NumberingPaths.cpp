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
const int N = 202;
ll OO = (ll)1e17;

ll dp[N][N] , dp2[N][N];
class NumberingPaths {
public:
	void solve(istream& cin, ostream& cout) {
//	    freopen("o.txt","w",stdout);
        int n;
        int testCases = 0;
        while(cin >> n){
            int mxCity = 0;
            for(int i=0;i<N-1;i++){
                for(int j=0;j<N-1;j++){
                    dp[i][j] = 0;
                    dp2[i][j] = OO;
                }
            }
            for(int i =0;i<n;i++){
                int u , v;
                cin >> u >> v;
                dp[u][v] = 1;
                dp2[u][v] = (ll)-1e9;
                mxCity = max(mxCity,max(u,v));
            }
            for(int i=0;i<=mxCity;i++)
                dp[i][i] = 0 , dp2[i][i] = 0;
            for(int k =0;k<=mxCity;k++){
                for(int i=0;i<=mxCity;i++){
                    for(int j = 0;j<=mxCity;j++){
                        dp[i][j] += dp[i][k] * dp[k][j];
                        if(dp2[i][j] > dp2[i][k] + dp2[k][j] && dp2[i][k] < 0 && dp2[k][j] < 0)
                           dp2[i][j] = min(dp2[i][j] , dp2[i][k] + dp2[k][j]);
                    }
                }
            }
            for(int k =0;k<=mxCity;k++){
                for(int i=0;i<=mxCity;i++){
                    for(int j = 0;j<=mxCity;j++){
                        if(dp2[i][j] > dp2[i][k] + dp2[k][j] && dp2[i][k] < 0 && dp2[k][j] < 0){
                            dp[i][j] = -1;
                        }
                    }
                }
            }
            cout << "matrix for city " << testCases++ << el;
            for(int i=0;i<=mxCity;i++){
                for(int j =0;j<=mxCity;j++){
                    cout << dp[i][j] << " \n"[j==mxCity];
                }
            }
        }
	}
};
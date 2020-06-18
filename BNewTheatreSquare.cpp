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
#include <numeric>
#include <assert.h>
using namespace std;
#define el  '\n'
#define ll long long
#define clr(a,b)memset(a,b,sizeof(a))
#define sz(a) (int)(a).size()
const long long N = (int)1e2 + 5, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

char grid[N][1003];
class BNewTheatreSquare {
public:
	void solve(istream& cin, ostream& cout) {
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            int n, m,x,y;
            cin >> n >> m >> x >> y;
            int totWhite = 0;
            for(int i = 1;i<=n;i++){
                for(int j = 1;j<=m;j++){
                    cin >> grid[i][j];
                    if(grid[i][j] == '.')
                        ++totWhite;
                }
            }
            int two = 0;
            for(int i = 1;i<=n;i++) {
                for (int j = 1; j <= m; j++) {
                    if(grid[i][j-1] == '.' && grid[i][j] == '.'){
                        two++;
                        grid[i][j-1] = grid[i][j] = '*';
                    }
                }
            }
            cout << min(totWhite*x,two*y + (totWhite-(2*two))*x) << el;
        }
	}
};
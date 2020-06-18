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
const long long N = (int)2e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

class GABMatrix {
public:
	void solve(istream& cin, ostream& cout) {
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            int n,m,a,b;
            cin >> n>> m>> a >> b;
            if(n*a != m*b){
                cout << "NO\n";
                continue;
            }
            vector<vector<int>> mat(n, vector<int>(m));
            int ptr = 0;
            for(int i = 0;i<n;i++){
                for(int j = 0;j<a;j++,ptr%=m){
                    mat[i][ptr++] = 1;
                }
            }
            cout << "YES\n";
            for(int i =0;i<n;i++){
                for(int j =0;j<m;j++){
                    cout << mat[i][j];
                }
                cout << el;
            }
            
        }
	}
};
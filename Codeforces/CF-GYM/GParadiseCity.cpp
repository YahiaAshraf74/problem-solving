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
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

string grid[3];
class GParadiseCity {
public:
	void solve(istream& cin, ostream& cout) {
        int t;
        cin >> t;
        while(t--){
            int n;
            cin >> n;
            cin >> grid[0] >> grid[1] >> grid[2];
            int mx = 0;
            for(int i=0;i<n;i++){
                int cnt = 0;
                for(int j = 0;j<3;j++){
                    for(int k = 0 , k2 = i*3;k<3;k++,k2++){
                        if(grid[j][k2] == '*')
                            cnt += 4;
                    }
                }
                mx = max(mx,cnt);
            }
            cout << mx << el;
        }
	}
};
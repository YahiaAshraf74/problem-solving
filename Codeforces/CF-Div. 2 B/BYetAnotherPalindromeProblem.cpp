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
#include <assert.h>
using namespace std;
#define el  '\n'
#define ll long long
#define clr(a,b)memset(a,b,sizeof(a))
#define sz(a) (int)(a).size()
const long long N = 5005, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;


vector<int> adj[N];
class BYetAnotherPalindromeProblem {
public:
    void init(){
        for(int i =0;i<N;i++)
            adj[i].clear();
    }

	void solve(istream& cin, ostream& cout) {
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            init();
            int n;
            cin >> n;
            for(int i =0;i<n;i++){
                int x;
                cin >> x;
                adj[x].push_back(i);
            }
            bool can= false;
            for(int i =0;i<=5000;i++){
                if(sz(adj[i]) >= 3 || (sz(adj[i]) == 2 && abs(adj[i][0] - adj[i][1]) >= 2) ){
                    can = true;
                    break;
                }
            }
            if(can){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
	}
};
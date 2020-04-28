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
const long long N = (int)2e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

class CFrogJumps {
public:
    void init(){

    }

	void solve(istream& cin, ostream& cout) {
        init();
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            string s;
            cin >> s;
            s = 'L' + s + 'R';
            int mx = 0;
            for(int i = 0 ,j = 0;i<sz(s);i++){
                if(s[i] != 'R'){
                    j++;
                }else{
                    mx = max(mx,j);
                    j = 1;
                }
            }
            cout << mx << el;
        }
	}
};
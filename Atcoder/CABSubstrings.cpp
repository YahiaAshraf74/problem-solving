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
const long long N = 2e5 + 74, OO = 0x3f3f3f3f, MOD = (long long) 1e9 + 7;

class CABSubstrings {
public:
	void solve(istream& cin, ostream& cout) {
        int n; 
        cin >> n;
        int ba = 0, a = 0 , b =0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            string s;
            cin >> s;
             if(s[0] == 'B' && s[sz(s)-1] == 'A'){
                ++ba;
            }else if(s[sz(s)-1] == 'A'){
                ++a;
            }else if(s[0] == 'B'){
                ++b;
            }
            for(int j = 0;j<sz(s)-1;j++){
                if(s[j] == 'A' && s[j+1] == 'B')
                    ++ans;
            }
        }
        if(ba > 1){
            ans += (ba -1);
            if(a > 0)
                ++ans , --a;
            if(b > 0)
                ++ans , --b;
        }else if(ba == 1){
            if(a > 0)
                ++ans , --a;
            if(b > 0)
                ++ans , --b;
        }
        ans += min(a,b);
        cout << ans << el;
	}
};
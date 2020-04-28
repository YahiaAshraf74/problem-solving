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

class AThreeFriends {
public:
    void init(){

    }

	void solve(istream& cin, ostream& cout) {
        init();
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            int a , b ,c;
            cin >> a >>  b >> c;
            ll mn = (ll)1e18;
            for(int i = -1;i<=1;i++){
                for(int j = -1;j<=1;j++){
                    for(int k =-1;k<=1;k++){
                        ll aa = a+i , bb = b+j , cc = c+k;
                        mn = min(mn,(ll)abs(aa-bb)+abs(aa-cc)+abs(bb-cc));
                    }
                }
            }
            cout << mn << el;
        }
	}
};
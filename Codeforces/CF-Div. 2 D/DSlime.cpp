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

class DSlime {
public:
    void init(){

    }

	void solve(istream& cin, ostream& cout) {
        init();
        int n;
        cin >> n;
        vector<int> v(n);
        int mnPos = OO, mxNeg = -OO;
        ll sum = 0;
        for(int &num : v){
            cin >> num;
            sum += (num > 0) ? num : -num;
            if(num <= 0){
                mxNeg = max(mxNeg,num);
            }else if(num >= 0){
                mnPos = min(mnPos,num);
            }
        }
        if(n == 1) {
            cout << v[0] << el;
        }else if(mnPos == OO){
            cout << sum - (2*(-mxNeg)) << el;
        }else if(mxNeg == -OO){
            cout << sum - (2*mnPos) << el;
        }else{
            cout << sum << el;
        }
	}
};
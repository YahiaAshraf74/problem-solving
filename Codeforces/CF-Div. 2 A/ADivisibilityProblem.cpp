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

class ADivisibilityProblem {
public:
    void init(){

    }

	void solve(istream& cin, ostream& cout) {
        init();
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            ll a , b;
            cin >> a >> b;
            ll d = a/b;
            if(a%b==0)
                cout << 0 << el;
            else 
                cout << b - (a-d*b) << el;
        }
	}
};
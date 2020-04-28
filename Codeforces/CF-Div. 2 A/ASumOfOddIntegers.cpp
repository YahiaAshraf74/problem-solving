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

class ASumOfOddIntegers {
public:
    void init(){

    }

	void solve(istream& cin, ostream& cout) {
        init();
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            int n ,k;
            cin >> n >> k;
            int sq;
            if(n&1){
                sq = (int)sqrt(n);
                if(sq%2==0)
                    sq--;
            }else{
                sq = (int)sqrt(n);
                if(sq%2==1)
                    sq--;
            }
            if(k >n)
                cout << "NO\n";
            else if((n%2==k%2) && sq>=k){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
	}
};
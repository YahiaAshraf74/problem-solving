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

class CSimilarPairs {
public:
	void solve(istream& cin, ostream& cout) {
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            int n;
            cin >> n;
            vector<int> v(n);
            int cntOdd = 0 , cntEven = 0;
            for(int &i : v){
                cin >> i;
                cntOdd += i&1;
                cntEven += !(i&1);
            }
            sort(v.begin(),v.end());
            bool canFix = false;
            for(int i =0;i<sz(v)-1;i++){
                if(v[i+1] - v[i] == 1){
                    canFix = true;
                    break;
                }
            }
            if(cntEven%2==0 && cntOdd%2==0){
                cout << "YES\n";
            }else if(canFix){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
	}
};
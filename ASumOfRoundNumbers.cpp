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

class ASumOfRoundNumbers {
public:
	void solve(istream& cin, ostream& cout) {
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            int n;
            cin >> n;
            int tens = 1;
            vector<int> ans;
            while(n){
                int d = (n%10) * tens;
                if(d > 0){
                    ans.push_back(d);
                }
                n /=10;
                tens *= 10;
            }
            cout << ans.size() << el;
            for(int i : ans)
                cout << i << ' ';
            cout << el;
        }
	}
};
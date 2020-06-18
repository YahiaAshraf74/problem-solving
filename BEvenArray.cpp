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

class BEvenArray {
public:
	void solve(istream& cin, ostream& cout) {
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            int n;
            cin >> n;
            vector<int> v(n);
            int odds = 0, evens = 0, w = 0;
            for(int i = 0;i<n;i++){
                cin >> v[i];
                if(v[i]&1)
                    ++odds;
                else
                    ++evens;
                if(i%2 != v[i]%2)
                    ++w;
            }
            if(n%2==0){
                if(evens != odds){
                    cout << -1 << el;
                }else{
                    cout << w / 2 << el;
                }
            }else{
                if(evens != odds+1){
                    cout << -1 << el;
                }else{
                    cout << w / 2 << el;
                }
            }
        }
	}
};
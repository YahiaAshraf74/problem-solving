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
#define el	'\n'
#define ll long long
#define clr(a,b)memset(a,b,sizeof(a))
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

class BDiceTower {
public:
	void solve(istream& cin, ostream& cout) {
        int t;
        cin >> t;
        while(t--){
            ll  x;
            cin >> x;
            if(x%14 == 0 || x < 15){
                cout << "NO\n";
                continue;
            }
            ll m = x / 14;
            ll rem = (m-1) * 14;
            ll rem2 = x - rem;
            if(rem2 >= 15 && rem2 <= 20 ){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
	}
};
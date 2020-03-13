#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include<stack>
#include <complex>
#include <string>
#include <bitset>
#include <stdio.h>
#include <string.h>
#include<fstream>
#include <iomanip> 
using namespace std;
#define el	'\n'
#define ll long long
#define clr(a,b)memset(a,b,sizeof(a))
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

class FMOSalahRunningDownTheWing {
public:
	void solve(istream& cin, ostream& cout) {
        int T;
        cin >> T;
        while(T--){
            int n  ,m  , x , y;
            cin >> n >> m >> x >> y;
            int need = (x + y) * n;
            need -= m;
            if(y == 0 && need > 0){
                cout << -1 << el;
            }else{
                cout << max(need,0) << el;
            }
        }
	}
};
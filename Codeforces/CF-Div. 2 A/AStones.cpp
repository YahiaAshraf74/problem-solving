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

class AStones {
public:
	void solve(istream& cin, ostream& cout) {
        int t;
        cin >> t;
        while(t--){
            int a, b,c;
            cin >> a >> b >> c;
            int ans = 0;
            while(c>=2 && b >= 1){
                c -= 2;
                b -= 1;
                ans++;
            }
            while(a >=1 && b>=2){
                a -= 1;
                b -= 2;
                ans++;
            }
            cout << ans*3 << el;
        }
	}
};
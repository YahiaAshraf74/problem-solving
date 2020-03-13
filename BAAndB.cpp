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

ll cum[N];
class BAAndB {
public:
	void solve(istream& cin, ostream& cout) {
        for(ll i =1;i<=(ll)1e5+5;i++){
            cum[i] = cum[i-1] + i;
        }
        int t;
        cin >> t;
        while(t--){
            ll a , b;
            cin >> a >> b;
            ll dif = abs(a-b);
            for(ll i = 0;i<=(ll)1e5+5;i++){
                if((dif+cum[i])%2==0 && cum[i] >= dif){
                    cout << i << el;
                    break;
                }
            }
        }
	}
};
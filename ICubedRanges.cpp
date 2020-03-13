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

class ICubedRanges {
public:
	void solve(istream& cin, ostream& cout) {
        ll l ,r ;
        cin >> l >> r;
        ll cnt = 0;
        for(ll i = l;i<=r;i++){
            if(i > (ll)1e6){
                break;
            }
            if(i*i*i > r){
                break;
            }
            ++cnt;
        }
        cout << cnt << el;
	}
};
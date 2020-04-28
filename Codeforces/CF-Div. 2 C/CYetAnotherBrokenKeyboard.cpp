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

class CYetAnotherBrokenKeyboard {
public:
    void init(){

    }

	void solve(istream& cin, ostream& cout) {
        init();
        int n , k;
        string s;
        cin >> n >> k >>s;
        map<char,bool> mp;
        for(int i =0;i<k;i++){
            char c;
            cin >> c;
            mp[c] = true;
        }
        ll ans = 0 , curLen = 0;
        for(int i = 0;i<sz(s);i++){
            if(mp[s[i]]){
                curLen++;
            }else{
                ans += (ll)(curLen*(curLen+1))/2;
                curLen = 0;
            }
        }
        ans += (ll)(curLen*(curLen+1))/2;
        cout << ans << el;
	}
};
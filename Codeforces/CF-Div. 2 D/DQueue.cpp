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


class DQueue {
public:
    void init(){

    }

	void solve(istream& cin, ostream& cout) {
        init();
        int n;
        cin >> n;
        vector<pair<int,int>> v(n);
        for(int i  =0;i<n;i++){
            cin >> v[i].first;
            v[i].second = i;
        }
        sort(v.begin(), v.end() );
        vector<int> ans(n);
        int mx = 0;
        for(int i = 0;i<n;i++){
            mx = max(mx,v[i].second);
            ans[v[i].second] = mx-v[i].second-1;
        }
        for(int i : ans)
            cout << i << ' ';
        cout << el;
	}
};
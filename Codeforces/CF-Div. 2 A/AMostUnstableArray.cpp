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
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using max_heap = priority_queue<T, vector<T>, less<T>>;

class AMostUnstableArray {
public:
    void init(){

    }

	void solve(istream& cin, ostream& cout) {
        init();
        int t;
        cin >> t;
        while(t--){
            int n,m;
            cin >> n >> m;
            if(n == 1){
                cout << 0 << el;
            }else if(n == 2){
                cout << m << el;
            }else{
                cout << m*2 << el;
            }
        }
	}
};
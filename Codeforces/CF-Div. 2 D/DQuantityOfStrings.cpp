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

long long power(long long b, long long p, long long MOD = (long long) 1e9 + 7) {
    long long res = 1;
    b %= MOD;
    for (; p; p >>= 1LL) {
        if (p & 1)res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}
class DQuantityOfStrings {
public:
    void init(){

    }

	void solve(istream& cin, ostream& cout) {
        init();
        int n, m,k;
        cin >> n >> m>> k;
        if(k == 1|| k > n){
            cout << power(m,n) << el;
        }else if(k == n){
            cout << power(m,(n+1)/2) << el;
        }else if(k%2==0){
            cout << m << el;
        }else{
            cout << m*m << el;
        }
	}
};
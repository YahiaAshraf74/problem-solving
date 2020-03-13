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

int cum[N];
bool isPrime(int n){
    n = __builtin_popcount(n);
    if(n==1)
        return false;
    for(int i = 2;i*i<=n;i++){
        if(n%i == 0)
            return false;
    }
    return true;
}
class LChance {
public:
	void solve(istream& cin, ostream& cout) {
	    for(int i =1;i<=(int)1e5;i++){
	        cum[i] = cum[i-1] + (isPrime(i));
	    }
        int t;
        cin >> t;
        while(t--){
            int l , r;
            cin >> l >> r;
            cout << cum[r] - cum[l-1] <<el;
        }
	}
};
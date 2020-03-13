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

class CExpectedBall {
public:
	void solve(istream& cin, ostream& cout) {
        int n , k;
        cin >> n >> k;
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
             ll x;
            cin >> x;
            sum +=x ;
        }
        if(k >= 2)
            --k;
        
        double ans = ((long double)k/n)*((long double)1.0/k)*(long double)sum;
//        long double p = (long double)(1.0/n);
//        for(int i = n-1 , j = k-1;j>=0;i--,j--){
//            p = (1.0-p)*(1.0/i);
//        }
        
        
        cout << fixed << setprecision(10)<< ans << el;
	}   
};
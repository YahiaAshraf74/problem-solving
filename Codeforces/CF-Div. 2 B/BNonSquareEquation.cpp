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
#define all(v)  ((v).begin()),((v).end())
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

ll n;
ll f(ll x){
    ll temp = x;
    ll sum = 0;
    while(temp){
        sum += temp%10;
        temp /= 10;
    }
    return sum * x;
}
bool can(ll m){
    return (((ll)m*m) + f(m)) - n == 0;
}
class BNonSquareEquation {
public:
	void solve(istream& cin, ostream& cout) {
        cin >> n;
        ll st = 1 , ed = 1e9;
        int ans = -1;
        while(st<=ed){
            ll mid = (st+ed)/2;
            if(can(mid)){
                st = mid + 1;
            }else{
                ed = mid - 1;
            }
        }
        cout << ans << el;
	}
};
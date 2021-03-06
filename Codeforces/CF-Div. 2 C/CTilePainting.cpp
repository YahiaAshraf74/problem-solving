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
#include<fstream>
#include <iomanip> 
using namespace std;
#define el	'\n'
#define ll long long
#define clr(a,b)memset(a,b,sizeof(a))
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

ll gcd(ll a, ll b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
class CTilePainting {
public:
	void solve(istream& cin, ostream& cout) {
        ll n;
        cin >> n;
        ll g = n;
        for(ll i = 2; i * i <= n;i++){
            if(n%i == 0){
                g = gcd(g,i);
                g = gcd(g,n/i);
            }
        }
        cout << g << el;
	}
};
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
#define el    '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define all(v)  ((v).begin()),((v).end())
const int N = 2e5 + 74, OO = 0x3f3f3f3f;

ll b[N];
ll gcd(ll a, ll b){
    if (b == 0)
        return a;
    return gcd(b, a % b);

}
class DSwords {
public:
    void solve(istream &cin, ostream &cout) {
        ll n;
        cin >> n;
        cin >> b[0];
        ll mx = b[0];
        for (int i = 1; i < n; i++) {
            cin >> b[i];
            mx = max(mx, b[i]);
        }
        ll sum = 0;
        ll g = mx - b[0];
        for (int i = 0; i < n; i++) {
            sum += (ll) mx - b[i];
            g = gcd(g, mx - b[i]);
        }
//        for(int i =0;i<n;i++){
//            if(b[i] + sum == mx){
//                cout << 1 << ' ' << sum  << el;
//                return;
//            }
//        }
        cout <<  sum / g << ' ' << g << el;
    }
};
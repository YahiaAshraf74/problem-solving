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
#define el    '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

set<ll,greater<ll>> numOfFact(ll n) {
    set<ll,greater<ll>> factors;
    while(n % 2 == 0) {
        factors.insert(2);
        n = n / 2;
    }
    for (ll i = 3; i * i<= n; i = i + 2) {
        while (n % i == 0) {
            factors.insert(i);
            n = n / i;
        }
    }
    if (n > 2)
        factors.insert(n);
    return factors;
}

ll primes[25997 + 3];
ll c[(ll) 3e5 + 3];

class BTaxes {
public:
    void solve(istream &cin, ostream &cout) {
        ll n, q;
        cin >> n >> q;
        for (ll i = 0; i < n; i++) {
            cin >> primes[i];
        }
        ll cost;
        for (ll i = 0; i < n; i++) {
            cin >> cost;
            c[primes[i]] = cost;
        }
        while (q--) {
            ll x;
            cin >> x;
            set<ll,greater<ll>> fact = numOfFact(x);
            vector<ll> remove;
            for(ll f : fact){
                if(c[f] == 0){
                    remove.push_back(f);
                }
            }
            for(ll i : remove){
                fact.erase(i);
            }

            ll cc = 0;
            while (true) {
                ll b = 0, mxB = 0, ff = -1;
                for (ll f : fact) {
                    if (c[f] > 0 && x % f == 0) {
                        b = x - (x / f);
                        b -= c[f];
                        if (mxB <= b) {
                            mxB = b;
                            ff = f;
                        }
                    }
                }
                if (ff == -1 || mxB == 0 || b < 0)
                    break;
                x /= ff;
                cc += c[ff];
                if(x == 1)
                    break;
            }
            cout << cc + x << el;
        }

    }
};
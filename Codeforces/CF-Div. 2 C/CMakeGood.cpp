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
const int N = 2e5 + 74, OO = 0x3f3f3f3f;

ll a[N];

class CMakeGood {
public:
    void solve(istream &cin, ostream &cout) {
        int t;
        cin >> t;
        while (t--) {
            ll n;
            cin >> n;
            ll sum = 0, xo = 0;
            for (ll i = 0; i < n; i++) {
                cin >> a[i];
                sum += a[i];
                xo ^= a[i];
            }
            vector<ll> ans;
            if (xo != 0) {
                sum += xo;
                ans.push_back(xo);
                xo ^= xo;
            }
            ans.push_back(sum);
            cout << (int)ans.size() << el;
            for(ll i:ans)
                cout << i << ' ';
            cout << el;
            ans.clear();
        }
    }
};
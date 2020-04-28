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
#define clr(a, b)memset(a,b,sizeof(a))
#define sz(a) (int)(a).size()
const long long N = (int) 5e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

struct Comparer {
    bool operator()(const bitset<10> &b1, const bitset<10> &b2) const {
        return b1.to_ulong() < b2.to_ulong();
    }
};

map<bitset<10>, int, Comparer> mp;

class Kompii {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            bitset<10> mask;
            while (x) {
                mask[x % 10] = 1;
                x /= 10;
            }
            mp[mask]++;
        }
        ll ans = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            for (auto it2 = it; it2 != mp.end(); it2++) {
                if(it2 == it)
                    ans += (ll)(it->second*((it->second)-1))/2;
                else 
                    ans += (ll)it->second * it2->second * ((it->first&it2->first) != 0);
            }
        }
        cout << ans << el;

    }
};
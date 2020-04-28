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
const long long N = (int) 2e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

int n, m, q;
map<string, int> mp;
int opp[N];
int par[N];

class MahmoudAndADictionary {
public:
    void init() {
        for (int i = 0; i < N; i++)
            par[i] = i;
        clr(opp, -1);
        mp.clear();
    }

    int find(int u) {
        if (u == par[u])
            return u;
        else
            return par[u] = find(par[u]);
    }

    bool join(int u, int v) {
        u = find(u), v = find(v);
        if (u == v)
            return false;
        par[u] = v;
        return true;
    }

    void solve(istream &cin, ostream &cout) {
        init();
        cin >> n >> m >> q;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            mp[s] = i;
        }
        for (int i = 0; i < m; i++) {
            int t;
            string s, s2;
            cin >> t >> s >> s2;
            int u = mp[s], v = mp[s2];
            int parU = find(u), parV = find(v);
            if (t == 1) {
                if (parU == find(v + n)) {
                    cout << "NO\n";
                } else {
                    cout << "YES\n";
                    join(parU, parV);
                    join(u + n, v + n);
                }
            } else {
                if (parU == parV) {
                    cout << "NO\n";
                } else {
                    cout << "YES\n";
                    join(u + n, v);
                    join(v + n, u);
                }
            }
        }
        while (q--) {
            string s, s2;
            cin >> s >> s2;
            int u = mp[s], v = mp[s2];
            int parU = find(u), parV = find(v);
            if (parU == parV) {
                cout << 1 << el;
            } else if (find(u) == find(v + n))
                cout << 2 << el;
            else
                cout << 3 << el;
        }
    }
};
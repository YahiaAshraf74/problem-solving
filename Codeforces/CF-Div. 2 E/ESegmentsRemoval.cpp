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
const long long N = 2e5 + 74, OO = 0x3f3f3f3f, MOD = (long long) 1e9 + 7;

int par[N], sz[N], a[N], l[N], r[N];
int lp[N], rp[N];

set<pair<int, int>> groups;

int find(int x) {
    if (x == par[x]) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

bool join(int a, int b) {
    a = find(a) , b = find(b);
    if (a == b)
        return false;
    groups.erase({-sz[a], a});
    groups.erase({-sz[b], b});
    sz[a] += sz[b];
    par[b] = a;
    lp[a] = min(lp[a], lp[b]);
    rp[a] = max(rp[a], rp[b]);
    groups.insert({-sz[a], a});
    return true;
}

class ESegmentsRemoval {
public:
    void solve(istream &cin, ostream &cout) {
        int n;
        cin >> n;
        a[n + 1] = -1;
        a[0] = -2;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            l[i] = i - 1;
            r[i] = i + 1;
            lp[i] = rp[i] = i;
            par[i] = i;
            sz[i] = 1;
            groups.insert({-1, i});
            if (a[i] == a[i - 1])
                join(i, i - 1);
        }
        int ans = 0;
        while (groups.size() > 0) {
            int on = groups.begin()->second;
            groups.erase(groups.begin());
            ans++;
            int left = lp[find(on)];
            int right = rp[find(on)];
            r[l[left]] = r[right];
            l[r[right]] = l[left];
            if (a[r[right]] == a[l[left]])
                join(r[right], l[left]);
        }
        cout << ans << el;
    }
};
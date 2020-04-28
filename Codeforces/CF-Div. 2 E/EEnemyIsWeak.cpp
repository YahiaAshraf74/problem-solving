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
const long long N = (int) 1e6 + 2, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

int a[N];
vector<int> tree[N * 4];

class EEnemyIsWeak {
public:
    void init() {
        clr(a, 0);
        for (int i = 0; i < N * 4; i++)
            tree[i].clear();
    }

    void merge(vector<int> &p, vector<int> &l, vector<int> &r) {
        int i = 0, j = 0;
        while (i < l.size() && j < r.size()) {
            if (l[i] <= r[j])
                p.push_back(l[i++]);
            else
                p.push_back(r[j++]);
        }
        while (i < l.size())
            p.push_back(l[i++]);
        while (j < r.size())
            p.push_back(r[j++]);
    }

    void build(int n, int st, int ed) {
        if (st == ed) {
            tree[n].push_back(a[st]);
            return;
        }
        int mid = (st + ed) >> 1;
        build(n * 2 + 1, st, mid);
        build(n * 2 + 2, mid + 1, ed);
        merge(tree[n], tree[n * 2 + 1], tree[n * 2 + 2]);
    }

    int quary(int n, int st, int ed, int l, int r, int k) {
        if (st > r || ed < l)
            return 0;
        else if (st >= l && ed <= r) {
//            return lower_bound(tree[n].begin(), tree[n].end(), k) - tree[n].begin(); // number of element less than me
            return tree[n].end() - lower_bound(tree[n].begin(), tree[n].end(), k); // number of element greater than me
        } else {
            int mid = (st + ed) >> 1;
            return quary(n * 2 + 1, st, mid, l, r, k) + quary(n * 2 + 2, mid + 1, ed, l, r, k);
        }
    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        build(0, 0, n - 1);
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int pre = quary(0, 0, n - 1, 0, i - 1, a[i]); // element before me and greater than me
            int suf = (n - (i + 1)) - quary(0, 0, n - 1, i + 1, n - 1, a[i]); // element after me and less than me
            ans += (ll) pre * suf;
        }
        cout << ans << el;
    }
};
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
const long long N = (int) 1e4 + 2, M = (int) 1e6 + 2, OO = 0x3f3f3f3f, MOD = (long long) 1e9 + 7;

int a[N];
int tree[N * 4] , lazy[N * 4];
bitset<M> isPrime;

class CountingPrimes {
public:
    void init(int n) {
        memset(tree, 0, sizeof(tree[0]) * n * 4 + 1);
        memset(lazy, 0, sizeof(lazy[0]) * n * 4 + 1);
    }

    void sieve() {
        isPrime.set();
        isPrime[0] = isPrime[1] = 0;
        for (int i = 2; i*i < M; i++)
            if (isPrime[i])
                for (int j = i + i; j < M; j += i)
                    isPrime[j] = 0;
    }

    void build(int n, int st, int ed) {
        if (st == ed) {
            tree[n] = isPrime[a[st]];
            return;
        }
        int mid = (st + ed) >> 1;
        build(n * 2 + 1, st, mid);
        build(n * 2 + 2, mid + 1, ed);
        tree[n] = tree[n * 2 + 1] + tree[n * 2 + 2];
    }

    void updateRange(int n, int st, int ed, int l, int r, int val) {
        if (lazy[n] != 0) {
            tree[n] = (ed - st + 1) * isPrime[lazy[n]];
            if (st != ed)
                lazy[n * 2 + 1] = lazy[n], lazy[n * 2 + 2] = lazy[n];
            lazy[n] = 0;
        }
        if (ed < l || st > r)
            return;
        else if (st >= l && ed <= r) {
            tree[n] = (ed - st + 1)* isPrime[val];
            if (st != ed)
                lazy[n * 2 + 1] = lazy[n * 2 + 2] = val;
        } else {
            int mid = (st + ed) >> 1;
            updateRange(n * 2 + 1, st, mid, l, r, val);
            updateRange(n * 2 + 2, mid + 1, ed, l, r, val);
            tree[n] = tree[n * 2 + 1] + tree[n * 2 + 2];
        }
    }

    int quaryRange(int n, int st, int ed, int l, int r) {
        if (lazy[n] != 0) {
            tree[n] = (ed - st + 1) * isPrime[lazy[n]];
            if (st != ed)
                lazy[n * 2 + 1] = lazy[n], lazy[n * 2 + 2] = lazy[n];
            lazy[n] = 0;
        }
        if (ed < l || st > r)
            return 0;
        else if (st >= l && ed <= r) {
            return tree[n];
        } else {
            int mid = (st + ed) >> 1;
            return quaryRange(n * 2 + 1, st, mid, l, r) + quaryRange(n * 2 + 2, mid + 1, ed, l, r);
        }
    }

    void solve(istream &cin, ostream &cout) {
        sieve();
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            int n, q;
            cin >> n >> q;
            init(n);
            for (int i = 0; i < n; i++)
                cin >> a[i];
            build(0, 0, n - 1);
            cout << "Case " << testCases++ << ":\n\n";
            while (q--) {
                int type, l, r;
                cin >> type >> l >> r;
                if (type == 1) {
                    cout << quaryRange(0, 0, n - 1, l - 1, r - 1) << el << el;
                } else {
                    int val;
                    cin >> val;
                    updateRange(0, 0, n - 1, l - 1, r - 1, val);
                }
            }
        }
    }
};
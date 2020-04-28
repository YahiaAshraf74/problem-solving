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
const long long N = (int) 1e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

int a[N];
int tree[N * 4];

class RMQWithShifts {
public:
    void init() {
    }

    void build(int n, int st, int ed) {
        if (st == ed) {
            tree[n] = a[st];
            return;
        }
        int mid = (st + ed) / 2;
        build(n * 2 + 1, st, mid);
        build(n * 2 + 2, mid + 1, ed);
        tree[n] = min(tree[n * 2 + 1], tree[n * 2 + 2]);
    }

    void update(int n, int st, int ed, int idx) {
        if (st == ed) {
            tree[n] = a[idx];
            return;
        }
        int mid = (st + ed) / 2;
        if (idx >= st && idx <= mid) {
            update(n * 2 + 1, st, mid, idx);
        } else {
            update(n * 2 + 2, mid + 1, ed, idx);
        }
        tree[n] = min(tree[n * 2 + 1], tree[n * 2 + 2]);
    }

    int quary(int n, int st, int ed, int l, int r) {
        if (ed < l || st > r)
            return OO;
        else if (st >= l && ed <= r)
            return tree[n];
        else {
            int mid = (st + ed) / 2;
            return min(quary(n * 2 + 1, st, mid, l, r), quary(n * 2 + 2, mid + 1, ed, l, r));
        }
    }

    void solve(istream &cin, ostream &cout) {
        int n, q;
        cin >> n >> q;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        build(0, 0, n - 1);
        while (q--) {
            string s;
            cin >> s;
            vector<int> v;
            string num = "";
            for (int i = 0; i < sz(s); i++) {
                if (s[i] - '0' <= 9 && s[i] - '0' >= 0)
                    num += s[i];
                if (s[i] == ',' || s[i] == ')') 
                    v.push_back(stoi(num) - 1),num = "";
            }
            if (s[0] == 'q') {
                cout << quary(0, 0, n - 1, v[0], v[1]) << el;
            } else {
                int end = a[v[0]];
                for (int i = 0; i + 1 < sz(v); i++)
                    swap(a[v[i]], a[v[i + 1]]);
                a[v[sz(v) - 1]] = end;
                for (int i = 0; i < sz(v); i++)
                    update(0, 0, n - 1, v[i]);
            }
        }
    }
};
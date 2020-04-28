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

pair<int, int> tree[N * 4];
string s;

class ESerejaAndBrackets {
public:
    void init() {
        clr(tree,0);
    }

    void build(int n, int st, int ed) {
        if (st == ed) {
            (s[st] == '(') ? tree[n].first++ : tree[n].second++;
            return;
        }
        int mid = (st + ed) >> 1;
        build(n * 2 + 1, st, mid);
        build(n * 2 + 2, mid + 1, ed);
        auto left = tree[n * 2 + 1], right = tree[n * 2 + 2];
        if (left.first > right.second) {
            tree[n].first = left.first - right.second;
        } else {
            tree[n].second = right.second - left.first;
        }
        tree[n].first += right.first;
        tree[n].second += left.second;
    }

    pair<int, int> quary(int n, int st, int ed, int l, int r) {
        if (st > r || ed < l)
            return {0, 0};
        else if (st >= l && ed <= r)
            return tree[n];
        else {
            int mid = (st + ed) >> 1;
            auto left = quary(n * 2 + 1, st, mid, l, r);
            auto right = quary(n * 2 + 2, mid + 1, ed, l, r);
            pair<int,int> par;
            if (left.first > right.second) {
                par.first = left.first - right.second;
            } else {
                par.second = right.second - left.first;
            }
            par.first += right.first;
            par.second += left.second;
            return par;
        }
    }

    void solve(istream &cin, ostream &cout) {
        init();
        cin >> s;
        build(0,0,sz(s)-1);
        int q;
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r;
            --l ,--r;
            auto q = quary(0,0,sz(s)-1,l,r);
            cout << (r - l + 1 ) - (q.first + q.second) << el;
        }
    }
};
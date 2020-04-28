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
const long long N = (int) 3e4 + 2, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

pair<int, int> tree[N * 4];
string s;

class Brackets {
public:
    void init(int n) {
        memset(tree, 0, sizeof(tree[0]) * n * 4 + 1);
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

    void update(int n, int st, int ed, int idx) {
        if (st == ed && st == idx) {
            tree[n] = {0, 0};
            if(s[st] == '('){
                s[st] = ')', tree[n].second++;
            }else{
                s[st] = '(', tree[n].first++;
            }
        }else if(idx < st || idx > ed){
            return;
        }else{
            int mid = (st+ed)>>1;
            update(n*2+1,st,mid,idx);
            update(n*2+2,mid+1,ed,idx);
            auto left = tree[n*2+1] , right = tree[n*2+2];
            tree[n] = {0,0};
            if(left.first > right.second){
                tree[n].first = left.first - right.second;
            }else{
                tree[n].second = right.second - left.first;
            }
            tree[n].first += right.first;
            tree[n].second += left.second;
        }
    }

    void solve(istream &cin, ostream &cout) {
        int n, testCases = 1;
        while (cin >> n) {
            init(n);
            cin >> s;
            build(0, 0, n - 1);
            int m;
            cin >> m;
            cout << "Test " << testCases++ << ":\n";
            while (m--) {
                int x;
                cin >> x;
                if (x == 0) {
                    cout << ((tree[0].first || tree[0].second) ? "NO" : "YES") << el;
                } else {
                    update(0, 0, n - 1, x - 1);
                }
            }
        }
    }
};
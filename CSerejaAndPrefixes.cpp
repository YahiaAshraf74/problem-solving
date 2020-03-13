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

vector<pair<ll, pair<int, int>>> v2;
map<ll, int> ans;

ll calc(ll pos) {
    if (ans[pos])
        return ans[pos];
    int st = 0, en = (int) v2.size() - 1;
    while (st < en) {
        int mid = (st + en + 1) / 2;
        if (v2[mid].first > pos)
            en = mid - 1;
        else
            st = mid;
    }
    ll idx = pos - v2[st].first;
    ans[pos] = calc(idx % v2[st].second.first + 1);
    return ans[pos];
}

class CSerejaAndPrefixes {
public:
    void solve(istream &cin, ostream &cout) {
        int m;
        cin >> m;
        ll idx = 0;
        while (m--) {
            int type;
            cin >> type;
            if (type == 1) {
                int x;
                cin >> x;
                ans[++idx] = x;
            } else {
                int l, c;
                cin >> l >> c;
                v2.push_back({idx + 1, {l, c}});
                idx += (ll) l * c;
            }
        }
        int n;
        cin >> n;
        while (n--) {
            ll pos;
            cin >> pos;
            cout << calc(pos) << ' ';
        }
        ans.clear(), v2.clear();
    }
};
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

class DChips {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> banned(m);
        vector<bool> col(n+1, true), row(n+1, true);
        col[0] = row[0] = false;
        col[1] = col[n] = row[1] = row[n] = false;
        for (int i = 0; i < m; i++) {
            cin >> banned[i].first >> banned[i].second;
            col[banned[i].first] = row[banned[i].second] = false;
        }
        cout << min(count(row.begin(), row.end(), true) + count(col.begin(), col.end(), true),(n-2)*2 - (n&1)) << el;
    }
};
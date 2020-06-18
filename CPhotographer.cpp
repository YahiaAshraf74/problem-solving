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
#include <numeric>
#include <assert.h>

using namespace std;
#define el  '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define sz(a) (int)(a).size()
const long long N = (int) 2e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

class CPhotographer {
public:
    void solve(istream &cin, ostream &cout) {
        int n, size, low, high;
        cin >> n >> size >> low >> high;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            v[i] = {x * low + y * high, i + 1};
        }
        sort(v.begin(), v.end());
        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (size - v[i].first >= 0) {
                size -= v[i].first;
                mx++;
            } else {
                break;
            }
        }
        cout << mx << el;
        for (int i = 0; i < mx; i++) {
            cout << v[i].second << ' ';
        }
    }
};
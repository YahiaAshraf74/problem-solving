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

class DEventDates {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n;
        array<int,3> a[105];
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i][0] >> a[i][1];
            a[i][2] = i;
        }
        sort(a, a + n);
        int ans[105] = {}, last = -1;
        for (int i = 0; i < n; i++) {
            if (last != a[i][0]) {
                ans[a[i][2]] = a[i][0];
                last = a[i][0];
            } else {
                a[i][0]++;
                --i;
            }
            sort(a, a + n);
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
    }
};
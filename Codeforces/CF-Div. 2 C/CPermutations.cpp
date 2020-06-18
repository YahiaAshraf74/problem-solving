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

class CPermutations {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        map<int, int> idx;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            idx[b[i]] = i;
        }
        int mx = 1;
        for (int i = 1; i < n; i++) {
            if (idx[a[i]] > idx[a[i - 1]])
                ++mx;
            else
                break;
        }
        cout << n - mx << el;
    }
};
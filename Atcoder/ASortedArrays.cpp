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
const long long N = 2e5 + 74, OO = 0x3f3f3f3f, MOD = (long long) 1e9 + 7;

int a[N];

class ASortedArrays {
public:
    void solve(istream &cin, ostream &cout) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) 
            cin >> a[i];
        if (n <= 2)
            return (void) (cout << 1 << el);
        int ans = 1, dec = 0, inc = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                if (inc) {
                    inc = 0;
                    ans++;
                } else {
                    dec++;
                }
            } else if (a[i] < a[i + 1]) {
                if (dec) {
                    dec = 0;
                    ans++;
                } else {
                    inc++;
                }
            }
        }
        cout << ans;
    }
};
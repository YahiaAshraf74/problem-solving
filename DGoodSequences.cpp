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
const long long N = (int) 1e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

int a[N], dp[N];
vector<int> divisors[N];

void generateDivisors() {
    bitset<N> primes;
    primes.set();
    primes[0] = 0;
    primes[1] = 0;
    for (int i = 2; i < N; ++i)
        if (primes[i])
            for (int j = i; j < N; j += i)
                primes[j] = 0,
                        divisors[j].push_back(i);
}

class DGoodSequences {
public:
    void solve(istream &cin, ostream &cout) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        generateDivisors();
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            int mx = 1;
            for (int d : divisors[a[i]]) {
                mx = max(mx, dp[d]+1);
                ans = max(ans, mx);
            }
            for (int d : divisors[a[i]]) {
                dp[d] = mx;
            }
        }
        cout << ans << el;
        clr(dp, 0);
    }
};
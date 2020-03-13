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

#define mod 998244353
int primes[3], dp[5005][5005];

long long solve(int n, int r) {
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    if (dp[n][r])
        return dp[n][r];
    return dp[n][r] = (solve(n - 1, r) + solve(n - 1, r - 1)) % mod;
}

long long solve2(int n, int r) {
    long long ans = 0, fact = 1;
    for (int i = 0; i <= r; i++) {
        if (i)
            fact = (fact * i) % mod;
        ans = (ans + ((solve(n, i) * solve(r, i)) % mod) * fact) % mod;
    }
    return ans % mod;
}

class CTheIntriguingObsession {
public:
    void solve(istream &cin, ostream &cout) {
        cin >> primes[0] >> primes[1] >> primes[2];
        sort(primes, primes + 3);
        ll ans = solve2(primes[1], primes[0]);
        ans = ((ans * solve2(primes[2], primes[0])) % mod);
        ans = (ans * solve2(primes[2], primes[1])) % mod;
        cout << ans;
    }
};
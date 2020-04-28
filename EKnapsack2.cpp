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
const long long N = 102, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

int n, totW;
pair<int, int> a[N];
int dp[(int) 1e5 + 2];

class EKnapsack2 {
public:
    void init() {
        clr(dp, OO);
    }


    void solve(istream &cin, ostream &cout) {
        init();
        cin >> n >> totW;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
            sum += a[i].second;
        }
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int curV = sum; curV >= a[i].second; curV--)
                dp[curV] = min(dp[curV], dp[curV - a[i].second] + a[i].first);
        }
        int ans = 0;
        for (int i = 0; i <= sum; i++) {
            if (dp[i] <= totW)
                ans = max(ans, i);
        }
        cout << ans << el;
    }
};
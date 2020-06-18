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
const int N = (int) 2e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

int dir[N];
bool vis[N] , inCycle[N];

int dfs(int cur) {
    if (vis[dir[cur]])
        return cur;
    vis[dir[cur]] = true;
    return dfs(dir[cur]);
}

int cycleSize(int cur, int l, int init) {
    if (dir[cur] == init)
        return l + 1;
    if (inCycle[cur])
        return 1;
    inCycle[cur] = true;
    return cycleSize(dir[cur], l + 1, init);
}

long long power(long long b, long long p, long long MOD = (long long) 1e9 + 7) {
    long long res = 1;
    b %= MOD;
    for (; p; p >>= 1LL) {
        if (p & 1)res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res % MOD;
}

class DDirectedRoads {
public:
    void solve(istream &cin, ostream &cout) {
        int nodes;
        cin >> nodes;
        int remEdges = nodes;
        for (int i = 0; i < nodes; i++) {
            cin >> dir[i];
            dir[i]--;
        }
        int res = 1;
        for (int i = 0; i < nodes; i++) {
            if (vis[i] == true)
                continue;
            int cycleStart = dfs(i);
            int cycleLength = cycleSize(cycleStart, 0, cycleStart);
            if (cycleLength <= 1)
                continue;
            remEdges -= cycleLength;
            res = (res * (power(2, cycleLength) - 2)) % MOD;
        }
        res = (res * power(2, remEdges)) % MOD;
        cout << res << el;
    }
};
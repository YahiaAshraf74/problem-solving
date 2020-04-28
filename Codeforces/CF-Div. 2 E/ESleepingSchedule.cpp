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
const long long N = 2004, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

int n, h, l, r;
int a[N];
int mem[N][N];

class ESleepingSchedule {
public:
    void init() {
        clr(mem, -1);
    }

    bool isGood(int m) {
        return m >= l && m <= r;
    }

    int solve(int i, int t) {
        if (i == n)
            return 0;
        int &ret = mem[i][t];
        if (~ret)
            return ret;
        int time1 = (t+a[i])%h , time2 = (t+a[i]-1)%h;
        int ch1 = solve(i + 1, time1) + isGood(time1);
        int ch2 = solve(i + 1, time2) + isGood(time2);
        ret = max(ch1, ch2);
        return ret;
    }

    void solve(istream &cin, ostream &cout) {
        init();
        cin >> n >> h >> l >> r;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << solve(0, 0) << el;
    }
};
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include<stack>
#include <complex>
#include <string>
#include <bitset>
#include <stdio.h>
#include <string.h>
#include<fstream>
#include <iomanip>

using namespace std;
#define el    '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define all(v)  ((v).begin()),((v).end())
const int N = 27, M = 195, OO = 0x3f3f3f3f;

int n, m, f[N], d[N], t[N];
int mem[N][M][M];
int ans[N];
int totalTime;

int dp(int i, int rm, int taken) {
    if (rm < 0)
        return -OO;
    if (i == n || rm == 0) {
        return 0;
    }
    int &ret = mem[i][rm][taken];
    if (~ret)
        return ret;
    int ch1 = 0, ch2 = 0;
    if (f[i] - (d[i] * taken) > 0)
        ch1 = dp(i, rm - 1, taken + 1) + f[i] - (d[i] * taken);
    else
        ch1 = dp(i, rm - 1, taken);
    ch2 = dp(i + 1, rm - t[i], 0);
    return ret = max(ch1, ch2);
}

void build(int i, int rm, int taken) {
    if (i == n || rm == 0) {
        return;
    }
    int optimal = dp(i, rm, taken);
    int ch1 = 0, ch2 = 0;
    if (f[i] - (d[i] * taken) > 0)
        ch1 = dp(i, rm - 1, taken + 1) + f[i] - (d[i] * taken);
    else
        ch1 = dp(i, rm - 1, taken);
    ch2 = dp(i + 1, rm - t[i], 0);
    if (optimal == ch2 && optimal != ch1) {
        build(i + 1, rm - t[i], 0);
        totalTime += t[i];
    } else if (optimal == ch1) {
        ans[i]++;
        totalTime++;
        build(i, rm - 1, taken + 1);
    }
}

class GoneFishing {
public:
    void solve(istream &cin, ostream &cout) {
        bool newLine = false;
        while (cin >> n) {
            if (!n)
                break;
            if (newLine)
                cout << el;
            newLine = true;
            clr(mem, -1);
            clr(ans, 0);
            totalTime = 0;
            cin >> m;
            m *= 12;
            for (int i = 0; i < n; i++) {
                cin >> f[i];
            }
            for (int i = 0; i < n; i++) {
                cin >> d[i];
            }
            for (int i = 0; i < n - 1; i++) {
                cin >> t[i];
            }
            int mx = dp(0, m, 0);
            build(0, m, 0);
            cout << (ans[0] + max((m - totalTime), 0)) * 5;
            for (int i = 1; i < n; i++) {
                cout << ", " << ans[i] * 5;
            }
            cout << el << "Number of fish expected: " << mx << el;
        }
    }
};
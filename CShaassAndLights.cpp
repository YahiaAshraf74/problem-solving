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
const int N = 1e3 + 5, OO = 0x3f3f3f3f;
const ll MOD = (ll) 1e9 + 7;
ll C[N][N], pows[N];


class CShaassAndLights {
public:
    void solve(istream &cin, ostream &cout) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i)
                    C[i][j] = 1;
                else
                    C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
            }
        }
        pows[0] = pows[1] = 1;
        for (int i = 2; i < N; ++i)
            pows[i] = (2 * pows[i - 1]) % MOD;
        int n, m;
        cin >> n >> m;
        vector<int> vec;
        for (int i = 0; i < m; ++i) {
            int a;
            cin >> a;
            vec.push_back(a);
        }
        sort(all(vec));
        vector<int> dif;
        dif.push_back(vec[0] - 1);
        for (int i = 1; i < m; ++i)
            dif.push_back(vec[i] - vec[i - 1] - 1);
        dif.push_back(n - vec.back());
        ll ans = 1;
        for (int i = 1; i < m; ++i)
            ans = (ans * pows[dif[i]]) % MOD;
        int sum = dif[0];
        for (int i = 1; i <= m; ++i) {
            sum += dif[i];
            ll p = C[sum][dif[i]];
            ans = (ans * p) % MOD;
        }
        cout << ans;
    }
};
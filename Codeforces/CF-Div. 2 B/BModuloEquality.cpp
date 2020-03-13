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

int a[N], b[N];

class BModuloEquality {
public:
    void solve(istream &cin, ostream &cout) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        map<int, int> mp, temp;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            mp[b[i]]++;
        }
        ll mn = OO;
        for (int i = 0; i < n; i++) {
            ll ans = (b[i] - a[0] + m) % m;
            for (int j = 0; j < n; j++)
                temp[(a[j] + ans) % m]++;
            bool flag = true;
            for (auto it : temp) {
                if (it.second != mp[it.first]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                mn = min(ans, mn);
            temp.clear();
        }
        cout << mn;
    }
};
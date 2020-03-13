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
const int N = 2e5 + 74, OO = 0x3f3f3f3f;

int a[N];
vector<pair<int, int>> la, lb;
class CBerryJam {
public:
    void solve(istream &cin, ostream &cout) {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            for (int i = 1; i <= 2 * n; i++) {
                cin >> a[i];
                if (a[i] == 2)
                    a[i] = -1;
            }
            la.push_back({0, 0});
            for (int i = 1 , ans = 0; i <= n; i++) {
                ans += a[i];
                la.push_back({i, ans});
            }
            lb.push_back({0, 0});
            for (int i = 1 , ans = 0; i <= n; i++) {
                ans += a[2 * n + 1 - i];
                lb.push_back({i, ans});
            }
            sort(lb.begin(), lb.end(), [&](pair<int, int> a, pair<int, int> b) {
                if (a.second - b.second != 0)
                    return (a.second < b.second);
                return (a.first > b.first);
            });
            int final = 0;
            pair<int, int> dif;
            for (int i = 0; i <= n; i++) {
                dif = {OO, -la[i].second};
                auto idx = lower_bound(lb.begin(), lb.end(), dif, [&](pair<int, int> a, pair<int, int> b) {
                    return (a.second < b.second);
                });
                if ((idx != lb.end()) && ((*idx).second == -la[i].second) && ((*idx).first + i >= final))
                    final = (*idx).first + i;
            }
            cout << (2 * n) - final << el;
            la.clear(), lb.clear();
        }
    }
};
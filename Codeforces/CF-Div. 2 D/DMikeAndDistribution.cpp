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
#include <assert.h>

using namespace std;
#define el    '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

pair<int, int> b[N];
int a[N];
vector<int> ans;

class DMikeAndDistribution {
public:
    void solve(istream &cin, ostream &cout) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(b , b + n, greater<pair<int, int>>());
        ans.push_back(b[0].second);
        for (int i = 1; i+1 < n; i += 2) {
            if (i + 1 <= n && a[b[i + 1].second] > a[b[i].second])
                ans.push_back(b[i + 1].second);
            else
                ans.push_back(b[i].second);
        }
        if(ans.size() < n/2+1)
            ans.push_back(b[n - 1].second);
        cout << ans.size() << el;
        for (int i : ans)
            cout << i+1 << ' ';
        ans.clear();
    }
};
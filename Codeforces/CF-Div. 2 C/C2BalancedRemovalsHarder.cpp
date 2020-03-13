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
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 5e4 + 74, OO = 0x3f3f3f3f;

int a[N][3];
vector<pair<int, int>> ans;
vector<int> idx;

int helpSolve(vector<int> indices, int d = 0) {
    if (indices.empty())
        return -1;
    if (d == 3)
        return indices[0];
    map<int, vector<int>> mp;
    for (int i : indices)
        mp[a[i][d]].push_back(i);
    int temp = -1;
    for (auto i : mp) {
        int cur = helpSolve(i.second, d + 1);
        if (cur == -1)
            continue;
        if (temp == -1) {
            temp = cur;
        } else {
            ans.push_back({temp, cur});
            temp = -1;
        }
    }
    return temp;
}

class C2BalancedRemovalsHarder {
public:
    void solve(istream &cin, ostream &cout) {
        int n;
        cin >> n;
        idx.resize(n);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> a[i][j];
            }
            idx[i - 1] = i;
        }
        helpSolve(idx);
        for (auto i : ans)
            cout << i.first << ' ' << i.second << el;
        ans.clear();
    }
};
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
const long long N = (int) 2e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;
template<typename T> using heap = priority_queue<T, vector<T>, greater<T>>;


class KSmallestSums {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n;
        while (cin >> n) {
            vector<vector<int>> vec(n, vector<int>(n));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cin >> vec[i][j];
                }
                sort(vec[i].begin(), vec[i].end());
            }
            for (int i = 1; i < n; i++) {
                heap<pair<int, int>> h;
                for (int j = 0; j < n; j++)
                    h.push({vec[i][j] + vec[i - 1][0], 0});
                for (int j = 0; j < n; j++) {
                    auto t = h.top();
                    h.pop();
                    vec[i][j] = t.first;
                    h.push({(vec[i][j] + vec[i - 1][t.second + 1] - vec[i - 1][t.second]), t.second + 1});
                }
            }
            for (int i = 0; i < n; i++)
                cout << vec[n - 1][i] << " \n"[i == n - 1];
        }
    }
};
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
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

class DConstructingTheArray {
public:
    void init() {
    }

    void solve(istream &cin, ostream &cout) {
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            init();
            int n;
            cin >> n;
            vector<int> v(n);
            min_heap<array<int, 3>> h;
            h.push({-n, 0, n - 1});
            int action = 1;
            while (!h.empty()) {
                auto sub = h.top();
                h.pop();
                int l = sub[1], r = sub[2];
                if (r < l) {
                    continue;
                } else if (r == l) {
                    v[l] = action++;
                    continue;
                }
                int len = -sub[0];
                int mid;
                if (len & 1) {
                    mid = (r + l) / 2;
                } else {
                    mid = (r + l - 1) / 2;
                }
                v[mid] = action++;
                h.push({-((mid-1)-l+1),l, mid - 1});
                h.push({-(r-(mid+1)+1),mid + 1, r});

            }
            for (int i = 0; i < v.size(); i++) {
                cout << v[i] << ' ';
            }
            cout << el;
        }
    }
};
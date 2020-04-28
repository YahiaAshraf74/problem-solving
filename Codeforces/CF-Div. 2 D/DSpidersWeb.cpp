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
const long long N = (int) 2e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

class DSpidersWeb {
public:
    void init() {

    }

    int getIntersection(vector<int> &v, int l, int r) {
        auto idxL = upper_bound(v.begin(), v.end(), l) - v.begin();
        auto idxR = lower_bound(v.begin(), v.end(), r) - v.begin() - 1;
        return max(idxR - idxL + 1, 0);
    }


    void solve(istream &cin, ostream &cout) {
        init();
        int n;
        cin >> n;
        vector<vector<int>> vec;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            vector<int> v;
            for (int j = 0; j < k; j++) {
                int x;
                cin >> x;
                v.push_back(x);
            }
            sort(v.begin(), v.end());
            vec.push_back(v);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < sz(vec[i]) - 1; j++) {
                if (getIntersection(vec[(i - 1 + n) % n], vec[i][j], vec[i][j + 1]) !=
                    getIntersection(vec[(i + 1) % n], vec[i][j], vec[i][j + 1])) {
                    ++cnt;
                }
            }
        }
        cout << cnt << el;
    }
};
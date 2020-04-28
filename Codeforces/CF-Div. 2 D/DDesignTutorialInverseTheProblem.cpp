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
const long long N = (int) 2e3 + 4, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

int a[N][N];

class DDesignTutorialInverseTheProblem {
public:
    void init() {

    }

    bool can(int idx, vector<int> &v) {
        for (int i = 0; i < sz(v); i++) {
            if (idx == i)
                continue;
            if (binary_search(v.begin(), v.end(), v[idx] - v[i]))
                return true;
        }
        return false;
    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n;
        cin >> n;
        bool ans = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
            if (a[i][i] != 0)
                ans = false;
        }
        vector<int> v;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[i][j] != a[j][i]) {
                    ans = false;
                    break;
                } else if(a[i][j] != 0){
                    v.push_back(a[i][j]);
                }
            }
        }
        sort(v.begin(), v.end());
        bool found = (sz(v) == n - 1);
        for (int i = 0; i < sz(v) && !found; i++) {
            if (can(i, v)) 
                found = true;
        }
        if (found && ans) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
};
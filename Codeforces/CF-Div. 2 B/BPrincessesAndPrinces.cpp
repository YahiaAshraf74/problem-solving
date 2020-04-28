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
const long long N = (int) 1e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

vector<vector<int>> v;
bool girl[N], boy[N];

class BPrincessesAndPrinces {
public:
    void init() {
        v.clear();
        clr(girl, 0);
        clr(boy, 0);
    }

    void solve(istream &cin, ostream &cout) {
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            init();
            int n;
            cin >> n;
            for (int i = 0; i < n; i++) {
                int k;
                cin >> k;
                vector<int> vec;
                for (int i = 0; i < k; i++) {
                    int x;
                    cin >> x;
                    vec.push_back(x);
                }
                sort(vec.begin(), vec.end());
                v.push_back(vec);
            }
            for (int i = 0; i < v.size(); i++) {
                for (int j = 0; j < v[i].size(); j++) {
                    if (boy[v[i][j]] == false) {
                        boy[v[i][j]] = true;
                        girl[i+1] = true;
                        break;
                    }
                }
            }
            bool can = false;
            pair<int, int> couple;
            for (int i = 1; i <= n; i++) {
                if (girl[i] == false) {
                    for (int j = 1; j <= n; j++) {
                        if (boy[j] == false) {
                            couple = {i, j };
                            can = true;
                            break;
                        }
                    }
                    if (can)
                        break;
                }
            }
            if (can) {
                cout << "IMPROVE\n" << couple.first << ' ' << couple.second << el;
            } else {
                cout << "OPTIMAL\n";
            }
        }
    }
};
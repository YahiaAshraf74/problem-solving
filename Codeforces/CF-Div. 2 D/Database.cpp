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

class Database {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n, m;
        while (cin >> n >> m) {
            cin.ignore();
            vector<vector<string>> table(n + 1, vector<string>(m + 1));
            for (int i = 0, j = 0; i < n; i++, j = 0) {
                string line;
                getline(cin, line);
                stringstream strStream(line);
                while (getline(strStream, table[i][j++], ','));
            }
//            map<string, int> mp;
//            int r1 = -1, r2 = 0, c1 = -1, c2 = 0;
//            for (int j = 0; j < m; j++) {
//                bool found = false;
//                for (int i = 0; i < n; i++) {
//                    if (mp[table[i][j]] != 0) {
//                        found = true;
//                        r1 = mp[table[i][j]];
//                        r2 = i;
//                    } else {
//                        mp[table[i][j]] = i;
//                    }
//                }
//                if (found && c1 == -1 && r1 != -1)
//                    c1 = j;
//                else if (found)
//                    c2 = j;
//                mp.clear();
//            }
//            if (r1 == -1) {
//                cout << "YES\n";
//            } else {
//                cout << "NO\n";
//                cout << r1 + 1 << ' ' << r2 + 1 << el << c1 + 1 << ' ' << c2 + 1 << el;
//            }
            bool found = false;
            int r1, r2, c1, c2;
            for (int j = 0; j < m; j++) {
                for (int j2 = j + 1; j2 < m; j2++) {
                    map<pair<string, string>, int> mp;
                    for (int i = 0; i < n; i++) {
                        pair<string, string> t(table[i][j], table[i][j2]);
                        if (mp.count(t)) {
                            found = true;
                            r1 = mp[t], r2 = i;
                            c1 = j, c2 = j2;
                            break;
                        } else {
                            mp[t] = i;
                        }
                    }
                    if (found)
                        break;
                }
            }
            if (found) {
                cout << "NO\n";
                cout << r1 + 1 << ' ' << r2 + 1 << el << c1 + 1 << ' ' << c2 + 1 << el;
            } else {
                cout << "YES\n";
            }

        }
    }
};
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

class B2CharacterSwapHardVersion {
public:
    void solve(istream &cin, ostream &cout) {
        int k;
        cin >> k;
        while (k--) {
            int n;
            string s, t;
            vector<pair<int, int>> ans;
            cin >> n >> s >> t;
            for (int i = 0; i < n; i++) {
                if (s[i] != t[i]) {
                    bool found = false;
                    for (int j = i + 1; j < n; j++) {
                        if (t[i] == s[j] && s[j] != t[j]) {
                            ans.push_back({i,i});
                            swap(s[i],t[i]);
                            ans.push_back({j, i});
                            swap(t[i], s[j]);
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        for (int j = i + 1; j < n; j++) {
                            if (t[i] == t[j] && s[j] != t[j]) {
                                ans.push_back({i, j});
                                swap(s[i], t[j]);
                                found = true;
                                break;
                            }
                        }
                    }
                    if(!found)
                        break;
                }
            }
            if (s != t) {
                cout << "No\n";
            } else {
                assert((int)ans.size() <= 2*n);
                cout << "Yes\n" << ans.size() << el;
                for (auto i : ans)
                    cout << i.first + 1 << ' ' << i.second + 1 << el;
            }
        }
    }
};
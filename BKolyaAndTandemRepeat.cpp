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
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

class BKolyaAndTandemRepeat {
public:
    void solve(istream &cin, ostream &cout) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        for (int sz = ((s.size() + k) / 2) * 2; sz > 0; sz -= 2) {
            for (int i = 0; i + sz <= (int) s.size() + k; ++i) {
                bool flag = true;
                for (int j = i; j < i + (sz / 2); ++j) {
                    int r = j + sz / 2;
                    if (r < (int) s.size() && s[j] != s[r])
                        flag = false;
                }
                if (flag) {
                    cout << sz;
                    return;
                }
            }
        }
    }
};
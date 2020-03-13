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
const int N = 1e6 + 74, OO = 0x3f3f3f3f;

string s;

class DBinaryStringMinimizing {
public:
    void solve(istream &cin, ostream &cout) {
        int q;
        cin >> q;
        while (q--) {
            ll n, k;
            cin >> n >> k;
            cin >> s;
            vector<ll> zeros;
            for (int i = 0; i < n; i++) {
                if (s[i] == '0') {
                    zeros.push_back(i);
                }
            }
            ll pos = 0, last = -1;
            for (int i = 0; i < (int) zeros.size(); i++) {
                if (zeros[i] - pos <= k && zeros[i] >= pos) {
                    k -= zeros[i] - pos;
                    ++pos;
                } else {
                    last = zeros[i];
                    break;
                }
            }
            string ans;
            for (int i = 0; i < pos; i++)
                ans.push_back('0');
            for (int i = 0; i < n; i++) {
                if (s[i] == '0' && pos > 0) {
                    --pos;
                    continue;
                } else {
                    ans.push_back(s[i]);
                }
            }
            if (last != -1) {
                for (int i = last; i > 0; --i) {
                    if (k > 0) {
                        swap(ans[i], ans[i - 1]);
                        --k;
                    } else {
                        break;
                    }
                }
            }
            cout << ans << el;
        }
    }
};
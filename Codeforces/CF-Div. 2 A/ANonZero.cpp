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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;
#define el  '\n'
#define ll long long
#define sz(a) (int)(a).size()
template<typename T> using heap = priority_queue<T, vector<T>, less<T>>;
using ordered_set =  tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
const long long N = 2e5 + 74, OO = 0x3f3f3f3f, MOD = (long long) 1e9 + 7;


class ANonZero {
public:
    void static solve(istream &cin, ostream &cout) {
        int t;
        cin >> t;
        while (t--) {
            int n, a[105] = {};
            cin >> n;
            int zeros = 0, sum = 0;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
                if (!a[i])
                    zeros++, ++a[i];
                sum += a[i];
            }
            cout << zeros + (sum == 0 ? 1 : 0) << el;

        }
    }
};
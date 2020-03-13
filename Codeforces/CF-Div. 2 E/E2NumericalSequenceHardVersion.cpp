#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include<stack>
#include <complex>
#include <string>
#include <bitset>
#include <stdio.h>
#include <string.h>
#include<fstream>
#include <iomanip>

using namespace std;
#define el    '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define all(v)  ((v).begin()),((v).end())
const int N = (int) 4e4, OO = 0x3f3f3f3f;


ll getSum(ll r) {
    return (r + 1) * r / 2;
}

ll sumSoFar(ll r, int need) {
    ll pw = 1;
    ll sum = 0;
    ll add = 0;
    for (int len = 1;; ++len) {
        if (pw * 10 - 1 < r) {
            ll cnt = pw * 10 - pw;
            if (need) {
                sum += add * cnt + getSum(cnt) * len;
                add += cnt * len;
            } else {
                sum += cnt * len;
            }
        } else {
            ll cnt = r - pw + 1;
            if (need) {
                sum += add * cnt + getSum(cnt) * len;
            } else {
                sum += cnt * len;
            }
            break;
        }
        pw *= 10;
    }
    return sum;
}

class E2NumericalSequenceHardVersion {
public:
    void solve(istream &cin, ostream &cout) {
        int q;
        cin >> q;
        while (q--) {
            ll k;
            cin >> k;
            --k;
            ll l = 1, r = 1e9;
            ll res = -1;
            while (r - l >= 0) {
                ll mid = (l + r) >> 1;
                if (sumSoFar(mid, 1) > k) {
                    res = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            k -= sumSoFar(res - 1, 1);
            l = 1, r = res;
            ll num = -1;
            while (r - l >= 0) {
                int mid = (l + r) >> 1;
                if (sumSoFar(mid, 0) > k) {
                    num = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            cout << to_string(num)[k - sumSoFar(num - 1, 0)] << el;
        }
    }
};

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

ll a[N];

class DArrayDivision {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n;
        cin >> n;
        if (n == 1)
            return (void) (cout << "NO" << el);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum & 1)
            return (void) (cout << "NO" << el);
        bool can = false;
        ll sumL = 0, sumR = 0;
        set<ll> st;
        for (int i = 0; i < n; i++) {
            sumL += a[i];
            sumR = sum - sumL;
            can |= sumL == sumR;
            if (sumL > sumR) {
                ll dif = sumL - sumR;
                if (dif & 1)
                    continue;
                dif >>= 1;
                if (st.find(dif) != st.end())
                    can = true;
            }
            st.insert(a[i]);
        }
        st.clear();
        for (int i = n - 1; i >= 0; i--) {
            sumR += a[i];
            sumL = sum - sumR;
            can |= sumL == sumR;
            if (sumL < sumR) {
                ll dif = sumR - sumL;
                if (dif & 1)
                    continue;
                dif >>= 1;
                if (st.find(dif) != st.end())
                    can = true;
            }
            st.insert(a[i]);
        }
        if(can)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
};
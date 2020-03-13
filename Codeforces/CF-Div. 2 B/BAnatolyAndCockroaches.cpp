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
#define el	'\n'
#define ll long long
#define clr(a,b)memset(a,b,sizeof(a))
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

class BAnatolyAndCockroaches {
public:
	void solve(istream& cin, ostream& cout) {
        int n;
        string s ;
        cin >> n >> s;
        int b = 0, r = 0;
        for (int i = 0; i < n; i += 2)
            if (s[i] != 'b')
                ++b;
        for (int i = 1; i < n; i += 2)
            if (s[i] != 'r')
                ++r;
        int cnt1 = max (b, r);
        b = 0, r = 0;
        for (int i = 0; i < n; i += 2)
            if (s[i] != 'r')
                ++r;
        for (int i = 1; i < n; i += 2)
            if (s[i] != 'b')
                ++b;
        int cnt2 = max (b, r);
        cout << min (cnt1, cnt2) << el;
	}
};
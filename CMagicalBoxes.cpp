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

int fpow(int x, int y) {
    int res = 1;
    while (y > 0) {
        if (y & 1)
            res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res;
}

pair<int, int> a[N];

class CMagicalBoxes {
public:
    void solve(istream &cin, ostream &cout) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first >> a[i].second;
        }
        sort(a, a + n);
        int i = 1;
        while (i<n) {
            a[i - 1].first++;
            a[i - 1].second = ceil((long double) a[i - 1].second / 4);
            if (a[i - 1].first == a[i].first) {
                if(a[i-1].second > a[i].second)
                    a[i].second += (a[i-1].second - a[i].second);
                i++;
            }else if (a[i - 1].second == 1){
                a[i].second += a[i-1].second;
                i++;
            }
        }
        while (true) {
            a[n - 1].second = ceil((long double) a[n - 1].second / 4);
            a[n - 1].first++;
            if(a[n-1].second == 1)
                break;
        }
        cout << a[n - 1].first<< el;
    }
};
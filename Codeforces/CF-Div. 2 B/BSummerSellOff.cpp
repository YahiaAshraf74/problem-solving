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
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

int n, k;
int arr[N][2];
pair<int, int> b[N];

class BSummerSellOff {
public:
    void solve(istream &cin, ostream &cout) {
        cin >> n >> k;
        int i;
        for (i = 0; i < n; i++) {
            cin >> arr[i][0] >> arr[i][1];
            int old = min(arr[i][0], arr[i][1]);
            int neww = min(2 * arr[i][0], arr[i][1]);
            b[i] = {neww - old, old};
        }
        sort(b, b + n);
        reverse(b, b + n);
        ll ans = 0;
        for (i = 0; i < k; i++)
            ans += b[i].first + b[i].second;
        for (i = k; i < n; i++)
            ans += b[i].second;
        cout << ans << el;
    }
};
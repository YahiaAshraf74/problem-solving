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

vector<pair<int, int> > v;
class BShooting {
public:
    void solve(istream &cin, ostream &cout) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v.push_back({x,i});
        }
        sort(all(v),
             [](pair<int, int> a, pair<int, int> b) {
                 return a.first > b.first;
             }
        );
        int ans = 0 ;
        for (int i = 0 , cnt = 0; i < n; i++ , cnt++) 
            ans += (v[i].first * cnt) + 1;
        cout << ans << el;
        for (int i = 0; i < n; i++) 
            cout << v[i].second+1 << ' ';
        v.clear();
    }
};
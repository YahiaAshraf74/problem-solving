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
const int N = 2e5 + 74, OO = 0x3f3f3f3f;

int a[N];
class DChristmasTrees {
public:
    void solve(istream &cin, ostream &cout) {
        int n, m;
        cin >> n >> m;
        map<int, int> mp;
        queue<int> q;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]] = 1;
        }
        for(int i = 0;i<n;i++){
            if(!mp[a[i]-1]){
                q.push(a[i]-1);
                mp[a[i]-1] = 1;
            }
            if(!mp[a[i]+1]){
                q.push(a[i]+1);
                mp[a[i]+1] = 1;
            }
        }
        ll ans = 0;
        while((int)v.size() < m){
            int t = q.front();
            q.pop();
            v.push_back(t);
            ans += mp[t];
            if(!mp[t-1]){
                q.push(t-1);
                mp[t-1] = mp[t] + 1;
            }
            if(!mp[t+1]){
                q.push(t+1);
                mp[t+1] = mp[t] + 1;
            }
        }
        cout << ans << el;
        for(int i : v)
            cout << i << ' ';
        cout << el;
    }
};
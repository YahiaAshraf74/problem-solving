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
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 2e5 + 74, OO = 0x3f3f3f3f;

vector<int> add[N] , del[N];
int l[N] , r[N];
class D2TooManySegmentsHardVersion {
public:
    void solve(istream &cin, ostream &cout) {
        int n , k;
        cin >> n >> k;
        int mxN = 0;
        for (int i = 0; i < n; ++i) {
            cin >> l[i] >> r[i];
            add[l[i]].push_back(i);
            del[r[i]+1].push_back(i);
            mxN = max(mxN,r[i]);
        }
        vector<int> ans;
        set<pair<int,int>> st;
        for(int i =0;i<=mxN;i++){
            for(auto j : add[i])
                st.insert({r[j],j});
            for(auto j : del[i])
                st.erase({r[j],j});
            while(st.size() > k){
                ans.push_back(st.rbegin()->second);
                st.erase(*st.rbegin());
            }
        }
        cout << ans.size() << el;
        for(auto i : ans){
            cout << i+1 << ' ';
        }
    }
};
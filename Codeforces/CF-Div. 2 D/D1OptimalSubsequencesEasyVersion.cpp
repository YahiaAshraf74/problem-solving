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
const int N = 100 + 5, OO = 0x3f3f3f3f;

pair<int,int> a[N];
class D1OptimalSubsequencesEasyVersion {
public:
    void solve(istream &cin, ostream &cout) {
        int n;
        cin >> n;
        for(int i =0;i<n;i++){
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a,a+n,[&](pair<int,int>a,pair<int,int>b){
            if(a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        });
        int m;
        cin >> m;
        vector<pair<int,int>> q;
        while(m--){
            int k , pos;
            cin >> k >> pos;
            for(int i = 0;i<k;i++){
                q.push_back(a[i]);
            }
            sort(all(q),[&](pair<int,int> a,pair<int,int> b){
                return a.second < b.second;
            });
            cout << q[pos-1].first << el;
            q.clear();
        }
    }
};
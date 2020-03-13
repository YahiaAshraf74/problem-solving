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
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

int n;
pair<pair<int, int>, int> a[2003];
int x[2003] , y[2003] , z[2003];
bool vis[2003];
bool f(int i, int j, int k) {
    auto p = a[i], p2 = a[j], p3 = a[k];
    if (min(p.first.first, p2.first.first) <= p3.first.first && p3.first.first <= max(p.first.first, p2.first.first))
        return true;
    if(min(p.first.second, p2.first.second) <= p3.first.second && p3.first.second <= max(p.first.second, p2.first.second))
        return true;
    if(min(p.second, p2.second) <= p3.second && p3.second <= max(p.second, p2.second))
        return true;
    return false;
}
bool check(int i,int j){
    int cntX = lower_bound(x,x+n,a[i].first.first) - x;
    int cntY = lower_bound(y,y+n,a[i].first.second) - y;
    int cntZ = lower_bound(z,z+n,a[i].second) - z;

    int cntX2 = lower_bound(x,x+n,a[j].first.first) - x;
    int cntY2 = lower_bound(y,y+n,a[j].first.second) - y;
    int cntZ2 = lower_bound(z,z+n,a[j].second) - z;

    if(cntX2-cntX == 1 && cntY2-cntY == 1 &&cntZ2-cntZ == 1 ){

        return  true;
    }
    else
        return false;
}
class C1BalancedRemovalsEasier {
public:
    void solve(istream &cin, ostream &cout) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i].first.first >> a[i].first.second >> a[i].second;
            x[i] = a[i].first.first , y[i] = a[i].first.second , z[i] = a[i].second;
            vis[i]= false;
        }
        sort(x,x+n);
        sort(y+1,y+n);
        sort(z,z+n);
        for(int i =0;i<n;i++){
            if(vis[i]) continue;
            for(int j = i+1;j<n;j++){
                if(vis[j])continue;
                if(check(i,j)){
                    vis[i] = vis[j] = true;
                    cout << i+1 << ' ' << j+1 << el;
                    break;
                }
            }
        }

    }
};
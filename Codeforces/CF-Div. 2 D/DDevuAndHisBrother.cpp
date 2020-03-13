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
#define el	'\n'
#define ll long long
#define clr(a,b)memset(a,b,sizeof(a))
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

int n , m;
int b[N] , a[N];
vector<int> v;
ll can(ll t){
    ll sum = 0;
    for(int i =0;i<n;i++){
        if(b[i] < t){
            sum += (ll)t - b[i];
        }
    }
    for(int i =0;i<m;i++){
        if(a[i] > t){
            sum += (ll)a[i] - t;
        }
    }
    return sum;
}
class DDevuAndHisBrother {
public:
	void solve(istream& cin, ostream& cout) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            v.push_back(b[i]);
        }
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
            v.push_back(a[i]);
        }
        sort(all(v));
        int l = 1 , r = 1e9;
        while(l < r){
            int m = (l+r+1)/2;
            if(can(m) <= can(m-1)){
                l = m;
            }else{
                r = m-1;
            }
        }
        cout << can(l) << el;
        v.clear();
	}
};
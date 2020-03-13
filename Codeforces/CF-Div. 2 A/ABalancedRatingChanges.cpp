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

int a[14000], ans[14000];

class ABalancedRatingChanges {
public:
    void solve(istream &cin, ostream &cout) {
        int n;
        cin >> n;
        int ans , sum =0;
        int p = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if(x%2==0){
                ans = x /2;
            }else{
                if(x<0){
                    if(p == 0){
                        ans = floor((double)x/2);
                        p = -1;
                    }else if(p == 1){
                        ans = floor((double)x/2);
                        p = 0;
                    }else if(p == -1){
                        ans = x /2;
                        p = 0;
                    }
                }else{
                    if(p == 0){
                        ans = ceil((double)x/2);
                        p = 1;
                    }else if(p == 1){
                        ans = x /2;
                        p = 0;
                    }else if(p == -1){
                        ans = ceil((double)x/2);
                        p = 0;
                    }
                }
            }
            cout << ans << el;
            sum += ans;
        }
//        cout << sum << el;
    }
};
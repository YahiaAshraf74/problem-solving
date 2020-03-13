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

bool vis[N];
int f[N], a[N];

class ENewYearParties {
public:
    void solve(istream &cin, ostream &cout) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            f[a[i]]++;
        }
        for (int i = 1; i <= (int) 2e5; i++) {
            if (f[i] >= 3)
                vis[i - 1] = true, vis[i] = true, vis[i + 1] = true;
            else if (f[i] == 2 && vis[i - 1] == false)
                vis[i - 1] = true, vis[i] = true;
            else if (f[i] == 2 && vis[i - 1] == true)
                vis[i] = true, vis[i + 1] = true;
            else if (f[i] == 1 && vis[i - 1] == false)
                vis[i - 1] = true;
            else if (f[i] == 1 && vis[i - 1] == true && vis[i] == false)
                vis[i] = true;
            else if (f[i] == 1 && vis[i - 1] == true && vis[i] == true)
                vis[i + 1] = true;
        }
        int mx = 0;
        for (int i = 0; i <= (int) 2e5 + 1; i++) {
            if (vis[i])
                mx++;
            vis[i] = false;
        }
        int mn = 0;
        for(int i=1;i<=(int)2e5;i++){
            if(f[i] > 0 && vis[i] == false && vis[i-1] == true){
                f[i-1] += f[i];
                f[i] = 0;
            }else if(f[i] > 0 && (f[i+1] > 0 ||f[i+2]>0)){
                f[i+1] += f[i];
                f[i] = 0;
                vis[i+1] = true;
                i++;
            }
        }
        for(int i =1;i<=(int)2e5;i++){
            if(vis[i] || f[i] > 0)
                mn++;
        }
        cout << mn << ' ' << mx << el;
        for (int i = 0; i < N; i++)
            vis[i] = false, f[i] = 0;
    }
};
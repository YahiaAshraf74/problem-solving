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
#define ff(i, a, b) for(int i = (a); (i <= (b)); ++i)
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

class CAnadiAndDomino {
public:
    void solve(istream &cin, ostream &cout) {
        int n, m;
        cin >> n >> m;
        int degree[8][8]={};
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            degree[u][v]++, degree[v][u]++;
        }
        if (n < 7) {
            cout << m << el;
        } else {
            int mx = 0;
            for(int i =1;i<=n;i++) {
                for(int j =i+1;j<=n;j++) {
                    int ans = m;
                    for(int k = 1;k<=n;k++) {
                        if (k != i && k != j && degree[i][k] && degree[j][k])
                            ans--;
                    }
                    mx = max(mx, ans);
                }
            }
            cout << mx;
        }
    }
};
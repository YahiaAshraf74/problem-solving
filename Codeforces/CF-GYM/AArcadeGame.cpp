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
const int N = 2e6 + 74, OO = 0x3f3f3f3f;

class AArcadeGame {
public:
    void solve(istream &cin, ostream &cout) {
        int factorial[10];
        factorial[0] = 1;
        for (int i = 1; i <= 9; i++)
            factorial[i] = i * factorial[i - 1];
        int T;
        cin >> T;
        while (T--) {
            string s;
            cin >> s;
            int sz = (int) s.size();
            int rank = 0;
            while (next_permutation(all(s))) 
                rank++;
            long double dp[3]={};
            dp[0] = 0;
            dp[1] = 1.0 / factorial[sz];
            for (int i = 2; i <= rank; i++) {
                dp[i%3] = dp[(i - 1)%3] * (1.0 / factorial[sz]) + dp[(i - 1)%3];
            }
            cout << fixed << setprecision(9) << dp[rank%3] << el;
        }
    }
};
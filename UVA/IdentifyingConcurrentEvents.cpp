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
const int N = 203, OO = 0x3f3f3f3f;

vector<string> events;
map<string, int> mp;
bool dp[N][N];
class IdentifyingConcurrentEvents {
public:
    void solve(istream &cin, ostream &cout) {
        int  testCases = 0;
        while (true) {
            int n;
            cin >> n;
            if (n == 0)
                break;
            mp.clear();
            events.clear();
            clr(dp,false);
            int top = 0;
            for (int i = 0; i < n; i++) {
                int m;
                cin >> m;
                int first = top;
                for (int j = 0; j < m; j++) {
                    string s;
                    cin >> s;
                    mp[s] = top;
                    events.push_back(s);
                    top++;
                }
                for (int j = first; j < top - 1; j++)
                    dp[j][j + 1] = true;
            }
            int m;
            cin >> m;
            while(m--){
                string s1, s2;
                cin >> s1 >> s2;
                dp[mp[s1]][mp[s2]] = true;
            }
            for (int k = 0; k < top; k++)
                for (int i = 0; i < top; i++)
                    for (int j = 0; j < top; j++)
                        dp[i][j] |= dp[i][k] & dp[k][j];
            string ans = "";
            int cnt = 0;
            for (int i = 0; i < top; i++) {
                for (int j = i + 1; j < top; j++) {
                    if (!dp[i][j] && !dp[j][i]) {
                        cnt++;
                        if (cnt <= 2)
                            ans = ans + "(" + events[i] + "," + events[j] + ") ";
                    }
                }
            }
            if (cnt != 0) {
                cout << "Case " << ++testCases << ", " << cnt << " concurrent events:" << el;
                cout << ans << el;
            } else {
                cout << "Case " << ++testCases << ", no concurrent events." << el;
            }
        }
    }
};
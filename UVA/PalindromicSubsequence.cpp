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
const int N = 1e3 + 4, OO = 0x3f3f3f3f;

string s;
pair<int, string> mem[N][N];

pair<int, string> dp(int i, int j) {
    if (i >= j) {
        if (i == j)
            return {1, string(1, s[i])};
        else
            return {0, ""};
    }
    pair<int, string> &ret = mem[i][j];
    if (~ret.first)
        return ret;
    if (s[i] == s[j]) {
        ret = dp(i + 1, j - 1);
        ret.first += 2;
        ret.second = s[i] + ret.second + s[i];
    } else {
        pair<int, string> ch1, ch2;
        ch1 = dp(i + 1, j);
        ch2 = dp(i, j - 1);
        if (ch1.first == ch2.first) {
            ret = min(ch1, ch2);
        } else {
            ret = max(ch1, ch2);
        }
    }
    return ret;
}

class PalindromicSubsequence {
public:
    void solve(istream &cin, ostream &cout) {
        while (cin >> s) {
            for (int i = 0; i < s.size(); i++) {
                for (int j = 0; j < s.size(); j++) {
                    mem[i][j].first = -1;
                    mem[i][j].second = "";
                }
            }
            pair<int, string> ans = dp(0, s.size() - 1);
            cout << ans.second << el;
        }
    }
};
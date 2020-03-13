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
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

class APrefixes {
public:
    void solve(istream &cin, ostream &cout) {
        string s;
        int n;
        cin >> n >> s;
        int cnt = 0;
        for (int i = 0; i + 1 < n; ++++i) {
            if (s[i] == s[i + 1]) {
                cnt++;
                if (s[i] == 'a')
                    s[i + 1] = 'b';
                else
                    s[i + 1] = 'a';
            }
        }
        cout << cnt << el << s;
    }
};
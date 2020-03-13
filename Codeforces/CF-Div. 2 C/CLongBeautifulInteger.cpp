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
const int N = 1e5 + 74, OO = 0x3f3f3f3f;


class CLongBeautifulInteger {
public:
    void solve(istream &cin, ostream &cout) {
        string s, s2;
        int n, k;
        cin >> n >> k >> s;
        s2 = s;
        for (int i = 0; i < k; i++) {
            for (int j = i + k; j < n; j += k) {
                if (j >= n)
                    break;
                s2[j] = s[i];
            }
        }
        for (int i = 0; i < n; i++) {
            if (s2[i] > s[i])
                break;
            else if (s2[i] < s[i]) {
                int kk = -1;
                for (int j = k - 1; j >= 0; j--) {
                    if (s[j] != '9') {
                        kk = j;
                        break;
                    }
                }
                for (int j = kk; j < n; j += k)
                    s2[j] = s[kk] + 1;
                for (int j = kk + 1; j < k; j++)
                    for (int p = j; p < n; p += k)
                        s2[p] = '0';
                break;
            }
        }
        cout << (int) s2.size() << el << s2 << el;
    }
};
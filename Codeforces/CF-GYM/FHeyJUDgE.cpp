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

class FHeyJUDgE {
public:
    void solve(istream &cin, ostream &cout) {
        int t;
        cin >> t;
        while (t--) {
            int a[8];
            string s;
            cin >> s;
            for (int i = 0; i < (int) s.size(); i++) {
                a[i] = (s[i] - 'A') + 1;
            }
            sort(a, a + 7);
            int f[8] = {};
            for (int i = 0; i < 7; i++) {
                f[a[i]]++;
            }
            bool ans = true;
            int need = 0;
            int num1 = -1, num2 = -1;
            for (int i = 1; i <= 5; i++) {
                if (f[i] > 0) {
                    f[i]--;
                } else {
                    if (i == 1)
                        ans = false;
                    need++;
                    if (need >= 3) {
                        ans = false;
                        break;
                    }
                    if (num1 == -1) {
                        num1 = i;
                    } else {
                        num2 = i;
                    }
                }
            }
            if (!ans) {
                cout << "NO\n";
                continue;
            }
            if (need == 1) {
                if (num1 == 1) {
                    ans = false;
                } else if (num1 == 2 && (f[1] < 2)) {
                    ans = false;
                } else if (num1 == 3) {
                    if (!((f[1] >= 3) || (f[1] >= 1 && f[2] >= 1)))
                        ans = false;
                } else if (num1 == 4) {
                    if (!((f[1] >= 2 && f[2] >= 1) || f[2] >= 2 || (f[1] >= 1 && f[3] >= 1)))
                        ans = false;
                } else if (num1 == 5) {
                    if (!((f[1] >= 1 && f[2] >= 2) || (f[3] >= 1 && f[2] >= 1) || (f[4] >= 1 && f[1] >= 1)))
                        ans = false;
                }
            } else {
                if (num1 == 2 && num2 == 3) {
                    ans = false;
                } else if (num1 == 2 && num2 == 4) {
                    if (!(f[1] >= 3 && f[3] >= 1))
                        ans = false;
                } else if (num1 == 2 && num2 == 5) {
                    if (!(f[1] >= 3 && f[4] >= 1))
                        ans = false;
                } else if (num1 == 3 && num2 == 4) {
                    if (!(f[2] >= 3 && f[1] >= 1))
                        ans = false;
                } else if (num1 == 3 && num2 == 5) {
                    if (!(f[1] >= 2 && f[4] >= 1 && f[2] >= 1))
                        ans = false;
                } else if (num1 == 4 && num2 == 5) {
                    if (!((f[2] >= 3 && f[3] >= 1) || (f[2] >= 2 && f[1] >= 1 && f[4] >= 1) ||
                          (f[3] >= 2 && f[1] >= 1 && f[2] >= 1) || (f[1] >= 2 && f[3] >= 1 && f[4] >= 1)))
                        ans = false;
                }
            }
            if (ans) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
};
 
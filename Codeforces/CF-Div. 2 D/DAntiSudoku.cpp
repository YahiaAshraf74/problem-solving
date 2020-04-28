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
#define el  '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define sz(a) (int)(a).size()
const long long N = (int) 2e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

class DAntiSudoku {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        int t;
        cin >> t;
        while (t--) {
            char s[12][12];
            for (int i = 1; i <= 9; i++) {
                for (int j = 1; j <= 9; j++) {
                    cin >> s[i][j];
                }
            }
            for (int i = 1, j = 1; i <= 9; i++, j += 3) {
                if (s[i][j] == '1')
                    s[i][j] = '2';
                else
                    s[i][j] = '1';
                if(j == 7)
                    j = -1;
                else if(j == 8)
                    j = 0 ;
            }
            for (int i = 1; i <= 9; i++) {
                for (int j = 1; j <= 9; j++) {
                    cout << s[i][j];
                }
                cout << el;
            }
        }
    }
};
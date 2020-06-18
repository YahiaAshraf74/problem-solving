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
#include <numeric>
#include <assert.h>

using namespace std;
#define el  '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define sz(a) (int)(a).size()
const long long N = (int) 2e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

class EPolygon {
public:

    bool checkPre(int i, int j, int n, vector<vector<char>> &mat) {
        if(j == n-1 || i == n-1)
            return true;
        if (j + 1 >= n || mat[i][j + 1] == '1') {
            return true;
        } else {
            bool valid = true;
            for (int k = i; k < n; k++) {
                if (mat[k][j] != '1') {
                    valid = mat[k-1][j+1] == '1';
                    break;
                }
            }
            return valid;
        }
    }

    void solve(istream &cin, ostream &cout) {
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            int n;
            cin >> n;
            vector<vector<char>> mat(n + 1, vector<char>(n + 1));
            for(int i =0;i<n;i++){
                for(int j = 0;j<n;j++){
                    cin >> mat[i][j];
                }
            }
            bool can = true;
            for (int i = n - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (mat[i][j] == '1' && !checkPre(i, j, n, mat)) {
                        can = false;
                        break;
                    }
                }
            }
            if (can) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
};
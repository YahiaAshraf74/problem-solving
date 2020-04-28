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
const long long N = 11, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

int n;
array<array<char, N>, N> a, b;

class MirrorMirror {
public:
    void init() {
    }

    bool isSame(array<array<char, N>, N> a, array<array<char, N>, N> b) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] != b[i][j])
                    return false;
            }
        }
        return true;
    }

    void rotate() {
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - i - 1; j++) {
                int temp = a[i][j];
                a[i][j] = a[n - 1 - j][i];
                a[n - 1 - j][i] = a[n - 1 - i][n - 1 - j];
                a[n - 1 - i][n - 1 - j] = a[j][n - 1 - i];
                a[j][n - 1 - i] = temp;
            }
        }
    }

    array<array<char, N>, N> reflecte(array<array<char, N>, N> a) {
        array<array<char, N>, N> c;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                c[i][j] = a[n - i - 1][j];
            }
        }
        return c;
    }

    void solve(istream &cin, ostream &cout) {
        int testCases = 1;
        while (cin >> n) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    cin >> a[i][j];
                for (int j = 0; j < n; j++)
                    cin >> b[i][j];
            }
            cout << "Pattern " << testCases++ << " was ";
            if (isSame(a, b)) {
                cout << "preserved.\n";
                goto beDone;
            }
            rotate();
            if (isSame(a, b)) {
                cout << "rotated 90 degrees.\n";
                goto beDone;
            }
            rotate();
            if (isSame(a, b)) {
                cout << "rotated 180 degrees.\n";
                goto beDone;
            }
            rotate();
            if (isSame(a, b)) {
                cout << "rotated 270 degrees.\n";
                goto beDone;
            } else {
                rotate();
                a= reflecte(a);
                if (isSame(a, b)) {
                    cout << "reflected vertically.\n";
                    goto beDone;
                }
                rotate();
                if (isSame(a, b)) {
                    cout << "reflected vertically and rotated 90 degrees.\n";
                    goto beDone;
                }
                rotate();
                if (isSame(a, b)) {
                    cout << "reflected vertically and rotated 180 degrees.\n";
                    goto beDone;
                }
                rotate();
                if (isSame(a, b)) {
                    cout << "reflected vertically and rotated 270 degrees.\n";
                } else {
                    cout << "improperly transformed.\n";
                }
            }
            beDone: int fuck;
        }
    }
};
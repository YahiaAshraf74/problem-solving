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

class DAliceBobAndCandies {
public:
    void solve(istream &cin, ostream &cout) {
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            int n;
            cin >> n;
            vector<int> v(n);
            int sum = 0;
            for (int &i : v)
                cin >> i ,sum += i;
            if (n == 1) {
                cout << 1 << ' ' << v[0] << ' ' << 0 << el;
                continue;
            }
            int p1 = 0, p2 = n - 1;
            int sumAlice = v[p1], sumBob = v[p2], moves = 2, preAlice = v[p1], preBob = v[p2];
            int turns = 0;
            while (p2-p1 > 1&& preBob <= preAlice) {
                preBob += v[--p2];
            }
            preAlice = 0;
            while (p2-p1 > 1) {
                if (turns % 2 == 0) {
                    while (p2-p1 > 1 && preAlice <= preBob) {
                        sumAlice += v[++p1];
                        preAlice += v[p1];
                    }
                    preBob = 0;
                } else {
                    while (p2-p1 > 1 && preBob <= preAlice) {
                        preBob += v[--p2];
                    }
                    preAlice = 0;
                }
                turns++;
                ++moves;
            }
            cout << moves << " " << sumAlice << " " << sum - sumAlice << el;
        }
        //Before submit the code generate at least 3 test cases and make sure from special and corner test cases.
    }
};
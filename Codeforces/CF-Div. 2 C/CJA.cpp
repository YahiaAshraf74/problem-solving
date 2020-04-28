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
#define lsb(x) (((int)log2(x)+1))
const long long N = (int) 2e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

class CJA {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            init();
            cout << "Case #" << testCases++ << ": ";
            int x, y;
            cin >> x >> y;
            if (x % 2 == y % 2) {
                cout << "IMPOSSIBLE" << el;
                continue;
            }
            bool isNegX = x < 0, isNegY = y < 0;
            if (isNegX)
                x = -x;
            if (isNegY)
                y = -y;
            bitset<32> maskX(x), maskY(y);
            bool can = false;
            string path = "";
            vector<pair<bitset<32>, bitset<32>>> v, v2;
            v.push_back({bitset<32>(x), bitset<32>(0)});
            v.push_back({bitset<32>(x-1), bitset<32>(2)});
            for (int i = max(lsb(x) - 1, 0); i < 31; i++) {
                bitset<32> pos(1LL << i), neg(((1LL << i) - x));
                v.push_back({pos, neg});
            }
            v2.push_back({bitset<32>(y), bitset<32>(0)});
            v.push_back({bitset<32>(y-1), bitset<32>(2)});

            for (int i = max(lsb(y) - 1, 0); i < 31; i++) {
                bitset<32> pos(1LL << i), neg(((1LL << i) - y));
                v2.push_back({pos, neg});
            }
            for (int i = 0; i < sz(v); i++) {
                for (int j = 0; j < sz(v2); j++) {
                    path = "";
                    can = true;
                    pair<bitset<32>, bitset<32>> xx = v[i], yy = v2[j];
                    pair<int, int> xi = {(int) (xx.first.to_ulong()), (int) (xx.second.to_ulong())};
                    pair<int, int> yi = {(int) (yy.first.to_ulong()), (int) (yy.second.to_ulong())};
                    int mxBit = max({lsb(xi.first), lsb(xi.second), lsb(yi.first), lsb(yi.second)});
                    for (int k = 0; k < mxBit; k++) {
                        int sum = xx.first[k] + xx.second[k] + yy.first[k] + yy.second[k];
                        if (sum != 1) {
                            can = false;
                            break;
                        } else {
                            if (xx.first[k]) {
                                if (isNegX) {
                                    path += "W";
                                } else {
                                    path += "E";
                                }
                            } else if (xx.second[k]) {
                                if (isNegX) {
                                    path += "E";
                                } else {
                                    path += "W";
                                }
                            } else if (yy.first[k]) {
                                if (isNegY) {
                                    path += "S";
                                } else {
                                    path += "N";
                                }
                            } else {
                                if (isNegY) {
                                    path += "N";
                                } else {
                                    path += "S";
                                }
                            }
                        }
                    }
                    if (can)
                        break;
                }
                if (can)
                    break;
            }
            if (can) {
                cout << path << el;
            } else {
                cout << "IMPOSSIBLE\n";
            }
        }
    }
};
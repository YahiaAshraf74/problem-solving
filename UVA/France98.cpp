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

class France98 {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        vector<string> names(16);
        for (int i = 0; i < 16; ++i)
            cin >> names[i];
        vector<vector<double> > beatChance(16, vector<double>(16));
        for (int i = 0; i < 16; ++i)
            for (int j = 0; j < 16; ++j) {
                cin >> beatChance[i][j];
                beatChance[i][j] /= 100;
            }
        vector<double> probabilityOld(16, 1);
        vector<double> probabilityNew(16);
        for (int round = 0, groupSize = 1; round < 4; ++round, groupSize *= 2) {
            for (int i = 0; i < 16; ++i) {
                int currentG = i / groupSize;
                int start;
                if (currentG % 2 == 0)
                    start = currentG * groupSize + groupSize;
                else
                    start = currentG * groupSize - groupSize;
                probabilityNew[i] = 0;
                for (int x = 0; x < groupSize; ++x)
                    probabilityNew[i] += probabilityOld[start + x] * beatChance[i][start + x];
                probabilityNew[i] *= probabilityOld[i];
            }
            probabilityOld = probabilityNew;
        }
        for (int i = 0; i < 16; ++i) {
            probabilityOld[i] *= 100;
            cout << setprecision(2) << fixed << left << setw(10) << names[i] << " p=" << probabilityOld[i] << "%\n";
        }
    }
};
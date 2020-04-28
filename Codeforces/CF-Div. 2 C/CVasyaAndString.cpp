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

class CVasyaAndString {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n, k;
        string s;
        cin >> n >> k >> s; 
        vector<int> idxA, idxB;
        idxA.push_back(-1), idxB.push_back(-1);
        for (int i = 0; i < sz(s); i++) {
            if (s[i] == 'a')
                idxA.push_back(i);
            else
                idxB.push_back(i);
        }
        if(k >= sz(idxA) || k >= sz(idxB))
            return (void)(cout << n << el);
        idxA.push_back(n), idxB.push_back(n);
        int mx = 0, len = 0;
        for (int i = 1; i < idxA.size(); i++) {
            len = (idxA[min(i + k, sz(idxA) - 1)] - 1) - (idxA[i - 1] + 1) + 1;
            mx = max(mx, len);
        }
        for (int i = 1; i + k < idxB.size(); i++) {
            len = (idxB[min(i + k, sz(idxB) - 1)] - 1) - (idxB[i - 1] + 1) + 1;
            mx = max(mx, len);
        }
        cout << mx << el;
    }
};
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

int a[N];
class BVerseForSanta {
public:
    void solve(istream &cin, ostream &cout) {
        int t;
        cin >> t;
        while (t--) {
            int n, s;
            cin >> n >> s;
            ll sum = 0;
            for (int i = 0; i < n; i++) {
                cin >> a[i];
            }
            int mxIdx = -1 , mx = 0;
            bool first = false;
            bool bb = false;
            for (int i = 0; i < n; i++) {
                sum += a[i];
                if (sum > s && first == false) {
                    mxIdx = 0 , mx = 0;
                    for (int j = 0; j <= i; j++) {
                        if (mx < a[j]) {
                            mx = a[j];
                            mxIdx = j;
                        }
                    }
                    sum = sum - a[mxIdx];
                    first = true;
                }
                if (sum > s && first == true) {
                    cout << mxIdx + 1 << el;
                    bb = true;
                    break;
                }
            }
            if(bb)
                continue;
            if(mxIdx == -1){
                cout << 0 << el;
                continue;
            }else{
                cout << mxIdx+1 << el;
            }
        }
    }
};
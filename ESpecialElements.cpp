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
const long long N = (int) 8e3 + 2, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

int a[N];
unordered_map<int,bool> cnt;

class ESpecialElements {
public:
    void solve(istream &cin, ostream &cout) {
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            int n;
            cin >> n;
            for (int i = 0; i < n; i++) {
                cin >> a[i];
            }
            for (int i = 0; i < n; i++) {
                int sum = a[i];
                for (int j = i + 1; j < n; j++) {
                    sum += a[j];
                    if(sum > 8000)
                        break;
                    cnt[sum] = true;
                }
            }
            int ans = 0;
            for(int i = 0;i<n;i++){
                if(cnt[a[i]] == true)
                    ++ans;
            }
            cout << ans << el;
            cnt.clear();
        }
    }
};
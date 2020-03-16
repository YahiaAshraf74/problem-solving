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
#define clr(a,b)memset(a,b,sizeof(a))
#define sz(a) (int)(a).size()
const long long N = 2e5 + 74, OO = 0x3f3f3f3f, MOD = (long long) 1e9 + 7;

int a[N];
class LittleDeepuAndArray {
public:
	void solve(istream& cin, ostream& cout) {
        int n;
        cin >> n;
        for(int i = 0;i<n;i++){
            cin >> a[i];
        }
        int m;
        cin >> m;
        while(m--){
            int x;
            cin >> x;
            for(int i = 0;i<n;i++){
                if(a[i] > x)
                    a[i]--;
            }
        }
        for(int i =0;i<n;i++)
            cout << a[i] << ' ';
	}
};
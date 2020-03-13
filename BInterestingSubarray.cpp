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
#define el	'\n'
#define ll long long
#define clr(a,b)memset(a,b,sizeof(a))
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 2e5 + 74, OO = 0x3f3f3f3f;

int a[N];
class BInterestingSubarray {
public:
	void solve(istream& cin, ostream& cout) {
        int t;
        cin >> t;
        while(t--){
            int ind = 0;
            int n;
            cin >> n;
            for(int i =0;i<n;i++){
                cin >> a[i];
            }
            for(int i =0;i<n;i++){
                if((i-1>=0 && a[i]-a[i-1] >=2)){
                    cout << "YES\n" << i << ' ' << i+1 << el;
                    goto O;
                }
                if((i+1<n && a[i] - a[i+1] >=2)){
                    cout << "YES\n" << i+1 << ' ' << i+2 << el;
                    goto O;
                }
            }
            cout << "NO\n";
            O:;
        }
	}
};
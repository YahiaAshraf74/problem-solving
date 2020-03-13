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
const int N = 3e5 + 74, OO = 0x3f3f3f3f;

ll a[N];
class DDominoForYoung {
public:
	void solve(istream& cin, ostream& cout) {
        int n;
        cin >> n;
        for(int i =0;i<n;i++){
            cin >> a[i];
        }
        ll cnt[2]={};
        for(int i =0;i<n;i++){
            cnt[0] += a[i]/2;
            cnt[1] += a[i]/2;
            cnt[i%2] += a[i]%2;
        }
        cout << min(cnt[0],cnt[1]);
	}
};
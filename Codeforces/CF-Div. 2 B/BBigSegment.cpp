#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include<stack>
#include <complex>
#include <string>
#include <bitset>
#include <stdio.h>
#include <string.h>
#include<fstream>
#include <iomanip>
using namespace std;
#define el	'\n'
#define ll long long
#define clr(a,b)memset(a,b,sizeof(a))
#define all(v)  ((v).begin()),((v).end())
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

pair<int,int> b[N];
class BBigSegment {
public:
	void solve(istream& cin, ostream& cout) {
        int n;
        cin >> n;
        int mn = OO , mx = 0;
        for(int i=0;i<n;i++){
            cin >> b[i].first >> b[i].second;
            mn = min(mn, b[i].first);
            mx = max(mx, b[i].second);
        }
        int ans = -1;
        for(int i =0;i<n;i++){
            if(b[i].first == mn && b[i].second == mx)
                ans = i+1;
        }
        cout << ans << el;
	}
};
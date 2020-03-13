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
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

class ARemainder {
public:
	void solve(istream& cin, ostream& cout) {
        int n , x , y;
        cin >> n >> x >> y;
        string s;
        cin >> s;
        reverse(all(s));
        int cnt = s[x] != '1';
        cnt += s[y] != '1';
        for(int i = 0;i<y;i++){
            if(s[i] == '1')
                ++cnt;
        }
        for(int i = y+1;i<x;i++){
            if(s[i] == '1')
                ++cnt;
        }
        int cnt2 = s[y] != '1';
        for(int i = 0;i<y;i++){
            if(s[i] == '1')
                ++cnt2;
        }
        for(int i = y + 1;i<n;i++){
            if(s[i] == '1' && i >= x)
                break;
            if(s[i] == '1')
                ++cnt2;
        }
        
        
        cout << min(cnt,cnt2) << el;
        
	}
};
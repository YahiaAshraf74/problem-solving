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

char s[N];
set<int> st;
class CGoodString {
public:
	void solve(istream& cin, ostream& cout) {
        int n;
        cin >> n;
        for(int i = 1;i<=n;i++){
            st.insert(i);
            cin >> s[i];
        }
        int cnt = 0;
        for(int i = 1;i<=n-1;i++){
            int idx = i;
            idx -= cnt;
            if(s[i] == s[i+1] && idx%2 == 1){
                ++cnt;
                st.erase(i);
            }
        }
        if((int)st.size()%2 == 1){
            int val = *st.rbegin();
            st.erase(val);
            ++cnt;
        }
        cout << cnt << el;
        for(auto i : st){
            cout << s[i];
        }
	}
};
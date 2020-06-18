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
#define clr(a,b)memset(a,b,sizeof(a))
#define sz(a) (int)(a).size()
const long long N = (int)2e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using ordered_set =  tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
class CSocialDistance {
public:
	void solve(istream& cin, ostream& cout) {
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            int n, k;
            cin >> n >> k;
            string s;
            cin >> s;
            set<int> st;
            map<int,bool> mp;
            for(int i = 1;i<=n;i++){
                if(s[i-1] == '1'){
                    st.insert(i);
                }
            }
            int mx = 0;
            int pre = -1;
            for(int i =1;i<=n;i++){
                if(st.find(i) != st.end()){
                    pre = i;
                    continue;
                }
                int next = *st.upper_bound(i);
                if((next - i > k || next < i) && (i - pre > k || pre == -1) ){
                    ++mx;
                    pre = i;
                    st.insert(i);
                }
            }
            cout << mx << el;
        }
	}
};
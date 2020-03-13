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
#define el    '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

int a[N];
class BTheFirstTask {
public:
    void solve(istream &cin, ostream &cout) {
        int T;
        cin >> T;
        while (T--) {
            int n;
            cin >> n;
            int mn = n + 1;
            set<int,greater<int>> st;
            int cnt =0;
            for(int i =0;i<n;i++){
                int x;
                cin >> x;
                if(st.find(x) == st.end()){
                    st.insert(x);
                    if(x == 1)
                        mn -= 2;
                }else{
                    cnt++;
                }
            }
            int temp = 0;
            int ans = mn;
            for(auto it = st.begin() ; it != st.end() ;it++){
                int ans2 = (*it) - ((int)st.size() - temp) + temp;
                ans = min(ans,ans2+cnt);
                temp++;
            }
            cout << ans << el;
            st.clear();
        }
    }
};
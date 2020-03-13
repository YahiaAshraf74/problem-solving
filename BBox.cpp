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

int a[N] , ans[N];
class BBox {
public:
	void solve(istream& cin, ostream& cout) {
        int q;
        cin >> q;
        while(q--){
            int n;
            cin >> n;
            bool flag = true;
            set<int> st;
            for(int i =1;i<=n;i++){
                cin >> a[i];
                if(a[i] < i){
                    flag = false;
                }
                st.insert(i);
            }
            if(!flag){
                cout << -1 << el;
                continue;
            }
            for(int i =1;i<=n;i++){
                if(st.find(a[i]) != st.end()){
                    ans[i] = a[i];
                    st.erase(a[i]);
                }else{
                    ans[i] = *(st.begin());
                    st.erase(st.begin());
                }
            }
            for(int i=1;i<=n;i++){
                cout << ans[i] << ' ';
            }
            cout << el;
        }
	}
};
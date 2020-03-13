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

set<int> st;
int a[N];
class CFriendsAndGifts {
public:
	void solve(istream& cin, ostream& cout) {
        int n;
        cin >> n;
        for(int i = 1;i<=n;i++){
            st.insert(i);
        }
        vector<int> zeros;
        for(int i =1;i<=n;i++){
            cin >> a[i];
            if(a[i] != 0){
                st.erase(a[i]);
            }else{
                zeros.push_back(i);
            }
        }
        for(int i =0;i<(int)zeros.size();i++){
            if(st.find(zeros[i]) != st.end()){
                if(zeros[i] == *st.begin()){
                    a[zeros[i]] = *(st.rbegin());
                    st.erase(*(st.rbegin()));
                }else{
                    a[zeros[i]] = *(st.begin());
                    st.erase(*(st.begin()));
                }
            }
        }
        for(int i =1;i<=n;i++){
            if(a[i] == 0){
                a[i] = *st.begin();
                st.erase(*st.begin());
            }
        }
        for(int i=1;i<=n;i++){
            cout << a[i] << ' ';
        }
        st.clear();
        zeros.clear();
	}
};
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
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

class BBalancedTunnel {
public:
	void solve(istream& cin, ostream& cout) {
        int n;
        cin >> n;
        queue<int> q;
        set<int> st;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            q.push(x);
            st.insert(x);
        }
        int cnt = 0;
        for(int i =0;i<n;i++){
            int x;
            cin >> x;
            if(st.find(x) == st.end()){
                q.pop();
                continue;
            }
            while(st.find(q.front()) == st.end()){
                q.pop();
            }
            if(x == q.front()){
                q.pop();
                st.erase(x);
            }else{
                ++cnt;
                st.erase(x);
            }
        }
        cout << cnt << el;
        st.clear();
        while(!q.empty())
            q.pop();
	}
};
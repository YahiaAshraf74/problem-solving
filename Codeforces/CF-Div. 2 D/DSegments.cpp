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
const int N = 1e3 + 74, OO = 0x3f3f3f3f;

pair<int,int> b[N];
class DSegments {
public:
	void solve(istream& cin, ostream& cout) {
        int n;
        cin >> n;
        for (int i = 0; i < n;  ++i) {
            cin >> b[i].first >> b[i].second;
            if(b[i].second > b[i].first)
                swap(b[i].first, b[i].second);
        }
        sort(b, b + n);
        vector<int> ans;
        int lst = OO;
        for(int i =0;i<n;i++){
            if(i ==0){
                ans.push_back(b[i].first);
                lst = b[i].first;
            }else{
                if(lst >= b[i].second){
                    continue;
                }else{
                    ans.push_back(b[i].first);
                    lst = b[i].first;
                }
            }
        }
        cout << ans.size() << el;
        for(int i : ans){
            cout << i << ' ' ;
        }
	}
};
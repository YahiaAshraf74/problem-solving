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
const int N = 2e5 + 74, OO = 0x3f3f3f3f;

int b[N];
queue<int> ans;
vector<int> res ;
set<int> q ;
class B1SocialNetworkEasyVersion {
public:
	void solve(istream& cin, ostream& cout) {
        int n ,k;
        cin >> n >> k;
        for(int i=0;i<n;i++){
            cin >> b[i];
        }
        for(int i =0;i<n;i++){
            bool f = q.find(b[i]) != q.end();
            if(!f){
                q.insert(b[i]);
                ans.push(b[i]);
            }
            if((int)ans.size() == k+1){
                q.erase(ans.front());
                ans.pop();
            }
        }
        int sz = (int)ans.size();
        cout << sz << el;
        while(sz--){
            res.push_back(ans.front());
            ans.pop();
        }
        reverse(all(res));
        for(int i : res){
            cout << i << ' ';
        }
        res.clear();
        q.clear();
	}
};
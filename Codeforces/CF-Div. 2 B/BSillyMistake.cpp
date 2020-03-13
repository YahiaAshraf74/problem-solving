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

int a[N];
class BSillyMistake {
public:
	void solve(istream& cin, ostream& cout) {
        int n;
        cin >> n;
        if(n&1){
            cout << -1 << el;
            return;
        }
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        vector<int> ans;
        map<int,int> mp , nmp;
        int b = 0 , cnt = 0;
        bool valid = true;
        for(int i =0;i<n;i++){
            if(valid == false){
                break;
            }
            if(a[i] > 0){
                if(mp[a[i]] == 0){
                    mp[a[i]] = 1;
                    ++b;
                    ++cnt;
                }else{
                    valid = false;
                }
            }else{
                if(mp[(a[i]*-1)] == 1){
                    mp[(a[i]*-1)] = 2;
                    --b;
                    ++cnt;
                }else{
                    valid = false;
                }
            }
            if(b == 0){
                mp.clear();
                ans.push_back(cnt);
                cnt =0;
            }
        }
        if(valid && b == 0){
            cout << (int)ans.size() <<el;
            for(int i =0;i<(int)ans.size();i++){
                cout << ans[i]  << ' ';
            }
        }else{
            cout << -1 << el;
        }
	}
};
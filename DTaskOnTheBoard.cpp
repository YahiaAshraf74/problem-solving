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
#define clr(a, b)memset(a,b,sizeof(a))
#define sz(a) (int)(a).size()
const long long N = (int) 2e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;
template<typename T> using heap = priority_queue<T, vector<T>, greater<T>>;

class DTaskOnTheBoard {
public:

    int check(pair<int,int> p,vector<int> &idx){
        int d = 0;
        for(int i = 0;i<idx.size();i++){
            d += abs(p.second - idx[i]);
        }
        return d;
    }
    void solve(istream &cin, ostream &cout) {
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            int n;
            string s;
            cin >> s >> n;
            sort(s.begin(), s.end());
            reverse(s.begin(), s.end());
            vector<int> v(n);
            vector<int> idx;
            map<int,int> mp;
            heap<pair<int,int>> h;
            for(int i = 0;i<n;i++){
                cin >> v[i];
                h.push({v[i],i});
            }
            vector<pair<int,int>> rem;
            string ans;
            ans.resize(n);
            while(!h.empty()){
                pair<int,int> t = h.top();
                h.pop();
                int temp = check(t,idx);
                if(temp == t.first){
                    idx.push_back(t.second);
                }else{
                    rem.push_back(t);
                }
                if(rem.size() > 0){
                    for(auto p : rem)
                        h.push(p);
                    rem.clear();
                }
            }
            cout << h.top().first << ' ' << h.top().second << el;

        }
        //Before submit the code generate at least 3 test cases and make sure from special and corner test cases.
    }
};
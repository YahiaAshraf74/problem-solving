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

int mat[30][30];
class EKeyboardPurchase {
public:
    void solve(istream &cin, ostream &cout) {
        int n, m;
        string s;
        cin >> n >> m >> s;
        map<pair<char, char>, int> mp;
        set<pair<int,pair<char,char>> , greater<pair<int,pair<char,char>> >> st;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1])
                continue;
            else {
                mp[{min(s[i], s[i + 1]), max(s[i], s[i + 1])}]++;
            }
        }
        for(auto it : mp){
            st.insert({it.second,{it.first.first,it.first.second}});
        }
        if(st.size() == 0){
            cout << 0 << el;
            return;
        }
        string ans = "";
        bool vis[27] = {};
        string temp = "";
        for(auto it : st){
            char c = it.second.first , c2 = it.second.second;
            if(!vis[c-'a'] && !vis[c2-'a']){
                ans = ans + temp;
                temp = "";
                temp.push_back(c);
                temp.push_back(c2);
                vis[c-'a'] = vis[c2-'a'] = true;
            }else if(!vis[c-'a']){
                int ch1 , ch2;
                for(int i =0;i<ans.size();i++){
                    if(ans[i] == c2){
                        ch1 = i;
                        break;
                    }
                }
                ch2 = ans.size() - ch1 - 1;
                if(ch1 > ch2){
                    temp = c + temp;
                }else{
                    temp.push_back(c);
                }
                vis[c-'a'] = true;
            }else if(!vis[c2-'a']){
                int ch1 , ch2;
                for(int i =0;i<ans.size();i++){
                    if(ans[i] == c){
                        ch1 = i;
                        break;
                    }
                }
                ch2 = ans.size() - ch1 - 1;
                if(ch1 > ch2){
                    temp = c2 + temp;
                }else{
                    temp.push_back(c2);
                }
                vis[c2-'a'] = true;
            }
        }
        if(temp.size() > 0){
            ans = ans + temp;
        }
        for(int i =0;i<ans.size();i++){
            for(int j=i;j<ans.size();j++){
                mat[ans[i]-'a'][ans[j]-'a'] = mat[ans[j]-'a'][ans[i]-'a'] = j-i;
            }
        }
        ll cnt = 0;
        for(int i =0;i<s.size()-1;i++){
            cnt += (ll)mat[s[i]-'a'][s[i+1]-'a'];
        }
        cout << cnt << el;
        clr(mat,0);
    }
};
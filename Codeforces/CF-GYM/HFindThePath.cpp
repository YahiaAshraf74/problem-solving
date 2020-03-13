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

vector<pair<int,int>> adj[N];
set<pair<int,int>> st;
//bool vis[N];
map<pair<int,int>,bool> vis;
class HFindThePath {
public:
	void solve(istream& cin, ostream& cout) {
        int T;
        cin >> T;
        while(T--){
            int n , m , start , l , k;
            cin >> n >> m >> start >> l >> k;
            st.clear();
            vis.clear();
            for(int i = 1;i<=n+1;i++){
                adj[i].clear();
            }
            for(int i =0;i<m;i++){
                int from , to , weight;
                cin >> from >> to >> weight;
                adj[from].push_back({to,weight});
                adj[to].push_back({from,weight});
            }
            l = max(n,l);
            queue<int> q;
            q.push(start);
            int dep = 1 , sz;
            while(!q.empty()){
                sz = q.size();
                while(sz--){
                    int u = q.front();
                    q.pop();
                    for(int i =0;i<(int)adj[u].size();i++){
                        int v = adj[u][i].first , w = adj[u][i].second;
                        if(!vis[{u,v}]){
                            vis[{u,v}] = true;
                            vis[{v,u}] = true;
                            q.push(v);
                            st.insert({dep, w});
                        }
                    }
                }
                ++dep;
                if(dep > l){
                    break;
                }
            }
            int mx = 0;
            for(auto i : st){
                if(i.first<= k){
                    mx = max(mx,i.second);
                }
            }
            cout << mx << el;
        }
	}
};
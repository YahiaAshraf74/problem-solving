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
#define el  '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define sz(a) (int)(a).size()
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const long long N = (int) 1e4 + 5, OO = (ll) 1e18, MOD = (int) 1e9 + 7;

vector<pair<int, int>> adj[2][N];
vector<array<int, 3>> edges;

class HighestPaidToll {
public:
    void init(int n) {
        for(int i =0;i<=n;i++)
            adj[0][i].clear() , adj[1][i].clear();
        edges.clear();
    }

    vector<ll> dijkstra(vector<pair<int, int>> *adj, int st, int ed, int n) {
        vector<ll> dist(n+1, OO);
        min_heap<pair<ll, int>> minHeap;
        minHeap.push({0, st});
        dist[st] = 0;
        while (!minHeap.empty()) {
            ll d = minHeap.top().first, u = minHeap.top().second;
            minHeap.pop();
            if (dist[u] < d)
                continue;
            for (auto it : adj[u]) {
                ll d2 = it.second, v = it.first;
                ll newDist = d + d2;
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    minHeap.push({dist[v], v});
                }
            }
        }
        return dist;
    }

    void solve(istream &cin, ostream &cout) {
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            int n, m, st, ed, totalCost;
            cin >> n >> m >> st >> ed >> totalCost;
            init(n);
            while (m--) {
                int u, v, c;
                cin >> u >> v >> c;
                adj[0][u].push_back({v, c});
                adj[1][v].push_back({u, c});
                edges.push_back({u, v, c});
            }
            vector<ll> dist = dijkstra(adj[0], st, ed, n);
            vector<ll> dist2 = dijkstra(adj[1], ed, st, n);
            int mx = -1;
            for (auto edge: edges) {
                if (dist[edge[0]] + dist2[edge[1]] + edge[2] <= totalCost)
                    mx = max(mx, edge[2]);
            }
            cout << mx << el;
        }
    }
};
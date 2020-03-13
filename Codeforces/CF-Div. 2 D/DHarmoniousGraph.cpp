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
#define el    '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 2e5 + 74, OO = 0x3f3f3f3f;

int par[N], sz[N];

struct disJoint {
    int connComp, sizeOfDisJoint;

    disJoint(int size) {
        connComp = sizeOfDisJoint = size;
        for (int i = 1; i <= size; i++)
            par[i] = i, sz[i] = 1;
    }

    int find(int node) {
        int root = node;
        while (root != par[root])
            root = par[root];
        while (node != root) {
            int next = par[node];
            par[node] = root;
            node = next;
        }
        return root;
    }

    bool unionSet(int node1, int node2) {
        int root1 = find(node1), root2 = find(node2);
        if (root1 == root2)
            return 0;
        else if (root1 > root2) {
            sz[root1] += sz[root2];
            par[root2] = root1;
        } else {
            sz[root2] += sz[root1];
            par[root1] = root2;
        }
        --connComp;
        return 1;
    }

    int numOfConnComp() {
        return connComp;
    }

    bool connected(int node1, int node2) {
        return find(node1) == find(node2);
    }

    int componentSize(int node) {
        return sz[find(node)];
    }

    int size() {
        return sizeOfDisJoint;
    }
};

class DHarmoniousGraph {
public:
    void solve(istream &cin, ostream &cout) {
        int n, m;
        cin >> n >> m;
        disJoint ds(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            ds.unionSet(u, v);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int mx = ds.find(i);
            int par = mx;
            for (int j = i; j <= mx; j++) {
                if (par == ds.find(j)) {
                    continue;
                } else {
                    ds.unionSet(i, j);
                    mx = ds.find(i);
                    par = mx;
                    ++ans;
                }
            }
            i = mx;
        }
        cout << ans << el;
    }
};
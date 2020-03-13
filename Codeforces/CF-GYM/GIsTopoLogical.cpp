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
const int N = 2e5 + 74, OO = 0x3f3f3f3f;

int a[N], b[N];
vector<pair<int, int>> zero;
vector<int> other;
vector<pair<int, int>> edges;

class GIsTopoLogical {
public:
    void solve(istream &cin, ostream &cout) {
        int T;
        cin >> T;
        while (T--) {
            int n;
            cin >> n;
            for (int i = 0; i < n; i++)
                cin >> a[i];
            for (int i = 0; i < n; i++) {
                cin >> b[i];
                if (b[i] == 0)
                    zero.push_back({a[i], i});
                else
                    other.push_back(i);
            }
            sort(zero.begin(), zero.end());
            bool valid = true;
            for (int i = 0; i < n; i++) {
                // invalid cases
                if (a[i] - b[i] > zero.size() || (b[i] != 0 && b[i] + 1 > other.size()) ||
                    (i < zero.size() && i < zero[i].first)) {
                    valid = false;
                    break;
                }
                for (int j = 0; j < a[i] - b[i]; j++)
                    edges.push_back({zero[j].second + 1, i + 1});
                for (int j = 0, k = 0; k < b[i]; j++, k++) {
                    if (other[j] == i)
                        j++;
                    edges.push_back({other[j] + 1, i + 1});
                }
            }
            if (!valid)
                cout << -1 << el;
            else {
                cout << edges.size() << el;
                for (auto edge : edges)
                    cout << edge.first << ' ' << edge.second << el;
            }
            zero.clear();
            other.clear();
            edges.clear();
        }
    }
};
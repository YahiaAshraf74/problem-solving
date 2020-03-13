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

using namespace std;
#define el    '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define all(v)  ((v).begin()),((v).end())
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

int b[N];
class A2048Game {
public:
    void solve(istream &cin, ostream &cout) {
        int q;
        cin >> q;
        while (q--) {
            int n;
            cin >> n;
            map<int,int> mp;
            for (int i = 0; i < n; i++) {
                cin >> b[i];
                if (b[i] <= 2048)
                    mp[b[i]]++;
            }
            for (int i = 2; i <= 2048; i<<=1)
                mp[i] += mp[i / 2] >> 1;
            if (mp[2048] > 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
};
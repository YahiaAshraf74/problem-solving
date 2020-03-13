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

class AMyFriendOfMisery {
public:
    void solve(istream &cin, ostream &cout) {
        int t;
        cin >> t;
        while (t--) {
            ll n;
            cin >> n;
            ll mn = 1e18 , sum = 0;
            for(int i = 0;i<n;i++){
                ll x;
                char c;
                cin >> x >> c;
                if(c == '-'){
                    mn = min(mn,x+25+sum);
                }else{
                    sum += x+25;
                }
            }
            cout << max((ll)0,mn - sum)  << el;
        }
    }
};
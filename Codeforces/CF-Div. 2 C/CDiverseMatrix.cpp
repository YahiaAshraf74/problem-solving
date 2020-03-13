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

ll m[505][505];
class CDiverseMatrix {
public:
	void solve(istream& cin, ostream& cout) {
        ll r , c;
        cin >> r >> c;
        if(r + c == 2){
            cout << 0 ;
            return;
        }
        if(r == 1 || c== 1){
            ll num = 2;
            for(int i = 0;i<r;i++){
                for(int j = 0;j<c;j++){
                    m[i][j] = num++;
                }
            }
        }else{
            ll st = r +c;
            for(int i = 0;i<r;i++){
                ll d = 1;
                for(int j = 0;j<c;j++){
                    m[i][j] = st * d;
                    d++;
                }
                --st;
            }
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << m[i][j] << ' ';
            }
            cout << el;
        }
	}
};
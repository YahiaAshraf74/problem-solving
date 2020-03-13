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

int a[N] , b[N];
class ASinglePush {
public:
	void solve(istream& cin, ostream& cout) {
        int t;
        cin >> t;
        while(t--){
            int n;
            cin >> n;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }
            for(int i =0;i<n;i++){
                cin >> b[i];
            }
            int dif = 0;
            int l = -1, r = -1;
            for(int i =0;i<n;i++){
                if(a[i] != b[i]){
                    l = i;
                    dif = b[i] - a[i];
                    break;
                }
            }
            for(int i = n-1;i>=0;i--){
                if(a[i] != b[i]){
                    r = i;
                    break;
                }
            }
            if(l == -1 && r == -1){
                cout << "YES\n";
                continue;
            }
            if(dif < 0){
                cout << "NO\n";
                continue;
            }
            for(int i=l;i<=r;i++){
                a[i] += dif;
            }
            bool f= true;
            for(int i =0;i<n;i++){
                if(a[i] != b[i]){
                    f = false;
                    break;
                }
            }
            if(f){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
	}
};
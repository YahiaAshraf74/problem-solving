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

int a[105];
bool vis[105];
class BMinimizeThePermutation {
public:
	void solve(istream& cin, ostream& cout) {
        int q;
        cin >> q;
        while(q--){
            int n;
            cin >>n;
            for(int i =0;i<n;i++){
                cin >> a[i];
                vis[i] = false;
            }
            int op = n- 1;
            for(int i = 1;i<=n;i++){
                int idx = -1;
                for(int j = 0;j<n;j++){
                    if(a[j] == i){
                        idx = j;
                        break;
                    }
                }
                for(int j = idx;op>0&&j>=i;j--,op--){
                    if(vis[j-1]){
                        break;
                    }else if (a[j] < a[j-1]){
                        vis[j-1] = true;
                        swap(a[j],a[j-1]);
                    }else{
                        break;
                    }
                }
            }
            for(int i =0;i<n;i++){
                cout << a[i] << ' ';
            }
            cout << el;
        }
	}
};
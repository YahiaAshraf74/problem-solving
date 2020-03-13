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

int a[N];
int n , x ,y ;
bool can(int idx){
    for(int i = max(0,idx-x);i<idx;i++){
        if(a[i] < a[idx])
            return false;
    }
    for(int i =idx+1;i<min(n,idx+y+1);i++){
        if(a[i] < a[idx])
            return false;
    }
    return true;
}
class ACityDay {
public:
	void solve(istream& cin, ostream& cout) {
        cin >> n >> x >> y;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i =0;i<n;i++){
            if(can(i)){
                cout << i + 1 << el;
                return;
            }
        }
	}
};
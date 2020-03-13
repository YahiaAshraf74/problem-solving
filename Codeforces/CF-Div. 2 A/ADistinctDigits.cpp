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

int f[11]={};
bool can(int num){
    for(int i =0;i<10;i++)
        f[i] = 0;
    while(num){
        f[num%10]++;
        num /=10;
    }
    for(int i =0;i<10;i++){
        if(f[i] > 1)
            return false;
    }
    return true;
}
class ADistinctDigits {
public:
	void solve(istream& cin, ostream& cout) {
        int l , r; 
        cin >> l >> r;
        for(int i = l;i<=r;i++){
            if(can(i)){
                cout << i << el;
                return ;
            }
        }
        cout << -1 << el;
	}
};
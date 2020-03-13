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
#include<fstream>
#include <iomanip> 
using namespace std;
#define el	'\n'
#define ll long long
#define clr(a,b)memset(a,b,sizeof(a))
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

class AMaximumSquare {
public:
	void solve(istream& cin, ostream& cout) {
        int k;
        cin >> k;
        while(k--){
            int n;
            cin >> n;
            int f[1003]={};
            for(int i =0;i<n;i++){
                int x;
                cin >> x;
                f[x]++;
            }
            int mx = 0 , sum = 0;
            for(int i =1000;i>=1;i--){
                sum += f[i];
                if(sum >= i){
                    mx = i;
                    break;
                }
            }
            cout << mx << el;
        }
	}
};
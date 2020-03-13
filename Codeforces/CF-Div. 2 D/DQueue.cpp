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
#define el	'\n'
#define ll long long
#define clr(a,b)memset(a,b,sizeof(a))
#define all(v)  ((v).begin()),((v).end())
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

ll b[N];
class DQueue {
public:
	void solve(istream& cin, ostream& cout) {
        int n;
        cin >> n;
        for(int i =0;i<n;i++){
            cin >> b[i];
        }
        sort(b, b + n);
        ll totalTime = 0 , ans = 0;
        for(int i =0;i<n;i++){
            if(totalTime <= b[i]){
                ++ans;
                totalTime += b[i];
            }
            
        }
        cout << ans << el;
	}
};
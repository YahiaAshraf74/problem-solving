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

int b[N] ,a[N];
class AArrays {
public:
	void solve(istream& cin, ostream& cout) {
        int n , m;
        cin >> n >> m;
        int k , k2;
        cin >> k >> k2;
        for(int i =0;i<n;i++){
            cin >> b[i];
        }
        for(int i =0;i<m;i++){
            cin >> a[i];
        }
        --k , --k2;
        if(b[k] < a[m - k2 - 1]){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
	}
};
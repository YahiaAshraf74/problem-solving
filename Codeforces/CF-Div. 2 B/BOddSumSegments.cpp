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
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 2e5 + 74, OO = 0x3f3f3f3f;

int a[N];
class BOddSumSegments {
public:
	void solve(istream& cin, ostream& cout) {
	    int q;
	    cin >> q;
	    while(q--){
	        int n ,k;
	        cin >> n >> k;
	        int cntOdd = 0;
	        for(int i =0;i<n;i++){
	            cin >> a[i];
	            if(a[i]&1)
	                cntOdd++;
	        }
	        cntOdd -= k;
	        if(cntOdd < 0 || cntOdd&1)
	            cout << "NO\n";
	        else{
	            cout <<"YES\n";
	            --k;
	            for(int i=0;i<n-1&&k;i++)
	                if(a[i]&1)
	                    cout << i+1 << ' ',k--;
                cout << n << el;
	        }
	    }
	}
};
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
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

class AYetAnotherDividingIntoTeams {
public:
	void solve(istream& cin, ostream& cout) {
        int q;
        cin >> q;
        while(q--){
            int n , a[105]={};
            cin >> n;
            for(int i =0;i<n;i++){
                cin >> a[i];
            }
            sort(a,a+n);
            bool two =false ;
            for(int i =0;i<n-1;i++){
                if(a[i+1]-a[i] == 1){
                    two = true;
                    break;
                }
            }
            if(two){
                cout << 2 << el;
            }else{
                cout << 1 << el;
            }
        }
	}
};
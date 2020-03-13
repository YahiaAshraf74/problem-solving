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

class BRoomsAndStaircases {
public:
	void solve(istream& cin, ostream& cout) {
        int t;
        cin >> t;
        while(t--){
            int n;
            cin >> n;
            string s;
            cin >>s;
            int ft = -1 , sd = -1;
            for(int i =0;i<n;i++){
                if(s[i] == '1' && ft == -1){
                    ft = i;
                    break;
                }
            }
            for(int i = n-1;i>=0;i--){
                if(s[i] == '1' && sd == -1){
                    sd =i;
                    break;
                }
            }
            int ans = -OO, ans2 = -OO;
            if(ft != -1)
                ans = (n - ft ) * 2;
            if(sd != -1)
                ans2 = (sd+1) * 2;
            if(ft == -1 && sd == -1)
                ans = n;
            cout << max(ans,ans2) << el;
        }
	}
};
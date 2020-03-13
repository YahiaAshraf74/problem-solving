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

vector<pair<int,int>> v;
map<int,int> mp;
class CBeautifulRegionalContest {
public:
	void solve(istream& cin, ostream& cout) {
	    int t;
	    cin >> t;
	    while(t--){
            mp.clear();
            v.clear();
	        int n;
	        cin >> n;
	        for(int i =0;i<n;i++){
	            int x;
	            cin >> x;
	            mp[x]++;
	        }
	        for(auto it:mp)
	            v.push_back({it.first,it.second});
	        sort(all(v),greater<pair<int,int>>());
	        int m = n /2 ;
	        int g = 0, s = 0 , b = 0;
	        g = v[0].second;
	        int i =1;
	        while(s <= g  && i < (int)v.size() ){
	            s += v[i++].second;
	        }
            while(b <= g && i < (int)v.size()){
                b += v[i++].second;
            }
            m -= (g+s+b);
            if(m < 0 || g == 0 || s == 0 || b == 0 || g + s + b > n/2 || b <= g || s <= g || n < 10){
                cout << "0 0 0\n";
                continue;
            }
            while(i <(int)v.size()){
                if(v[i].second > m || m == 0){
                    break;
                }else{
                    b += v[i].second;
                    m -= v[i].second;
                    i++;
                }
            }
            cout << g << ' ' << s << ' ' << b << el;
	    }
	}
};
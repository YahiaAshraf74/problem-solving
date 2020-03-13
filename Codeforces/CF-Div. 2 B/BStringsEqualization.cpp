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

class BStringsEqualization {
public:
	void solve(istream& cin, ostream& cout) {
        int q;
        cin >> q;
        while(q--){
            string s, t;
            cin >> s>> t;
            int f[27] = {};
            for(char c : s){
                if(f[c-'a'] == 0)
                    f[c-'a'] = 1;
            }
            bool flag = false;
            for(char c : t){
                if(f[c-'a'] == 1){
                    flag = true;
                    break;
                }
            }
            if(flag){
                cout << "YES\n";
            }else{
                cout << "NO\n" ;
            }
        }
	}
};
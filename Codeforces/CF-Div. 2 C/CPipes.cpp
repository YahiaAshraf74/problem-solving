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

class CPipes {
public:
	void solve(istream& cin, ostream& cout) {
        int q;
        cin >> q;
        while(q--){
            int n;
            cin >> n;
            string s[2];
            cin >> s[0] >> s[1];
            for(int i = 0;i<n;i++){
                if(s[0][i] == '1' || s[0][i] == '2')
                    s[0][i] = '1';
                else
                    s[0][i] = '2';
                if(s[1][i] == '1' || s[1][i] == '2')
                    s[1][i] = '1';
                else
                    s[1][i] = '2';
            }
            bool cur = 0;
            bool flag = true;
            for(int i =0;i<n;i++){
                if(s[0][i] == '2' && s[1][i] == '2') {
                    cur ^= 1;
                }else {
                    if((!cur && s[0][i] == '1') || (cur && s[1][i] == '1'))
                        continue;
                    if(i != 0 && i != n - 1){
                        flag = false;
                        break;
                    }
                    if(i == 0 && (s[0][0] == '2') || (i == n-1 && (!cur|| s[1][n-1] == '2') )){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag && cur){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
	}
};
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

class BAniaAndMinimizing {
public:
	void solve(istream& cin, ostream& cout) {
        int n , k;
        cin >> n >>k;
        string s;
        cin >> s;
        if((int)s.size() == 1 && k > 0){
            cout << 0 <<el;
        }else if((int)s.size() == 1 && k == 0){
            cout << s << el;
        }else{
            if(k > 0){
                if(s[0] != '1')
                    --k;
                s[0] = '1';
                int i = 1;
                for(int i = 1;i<(int)s.size();i++){
                    if(s[i] != '0' && k){
                        s[i] = '0';
                        --k;
                    }
                    if(k == 0)
                        break;
                }
            }
            cout << s << el;
        }
	}
};
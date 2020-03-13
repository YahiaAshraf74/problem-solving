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

class ABeautifulString {
public:
	void solve(istream& cin, ostream& cout) {
        int t;
        cin >> t;
        while(t--){
            string s,s2;
            cin >> s;
            bool flag = false;
            for(int i =0;i<(int)s.size();i++){
                if(s[i] != '?'){
                    s2.push_back(s[i]);
                }
                if(i+1 < (int)s.size() && s[i] == s[i+1] && s[i] != '?')
                    flag = true;
            }
            if(flag){
                cout << -1 << el;
            }else{
                for(int i = 0;i<(int)s.size();i++){
                    if(s[i] != '?'){
                        cout << s[i];
                    }else{
                        if(i==0){
                            if(s[i+1] != 'a')
                                s[i] = 'a';
                            if(s[i+1] != 'b')
                                s[i] = 'b';
                            if(s[i+1] != 'c')
                                s[i] = 'c';
                            cout << s[i] ;
                            continue;
                        }else if(i+1 == (int)s.size()){
                            if(s[i-1] != 'a')
                                s[i] = 'a';
                            if(s[i-1] != 'b')
                                s[i] = 'b';
                            if(s[i-1] != 'c')
                                s[i] = 'c';
                            cout << s[i];
                            continue;
                        }
                        if(s[i-1] != 'a' && s[i+1] != 'a')
                            s[i] = 'a';
                        if(s[i-1] != 'b' && s[i+1] != 'b')
                            s[i] = 'b';
                        if(s[i-1] != 'c' && s[i+1] != 'c')
                            s[i] = 'c';
                        cout << s[i] ;
                    }
                }
                cout << el;
            }
        }
	}
};
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

class AShuffleHashing {
public:
	void solve(istream& cin, ostream& cout) {
        int n;
        cin >>n;
        while(n--){
            string s, h;
            cin >> s >> h;
            if(h.size()<s.size()){
                cout << "NO\n";
                continue;
            }
            int f[30]={} , f2[30]={} ;
            for(char c : s)
                f[c-'a']++;
            bool flag = true;
            for(int i = 0;i<(int)h.size()-(int)s.size()+1;i++){
                flag = true;
                clr(f2,0);
                for(int j = i, sz = 0;sz<s.size();sz++,j++){
                    f2[h[j]-'a']++;
                }
                for(int j =0;j<26;j++){
                    if(f[j] != f2[j]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    break;
                }
            }
            if(flag){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
	}
};
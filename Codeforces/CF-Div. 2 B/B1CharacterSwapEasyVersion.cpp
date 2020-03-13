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
#include<fstream>
#include <iomanip> 
using namespace std;
#define el	'\n'
#define ll long long
#define clr(a,b)memset(a,b,sizeof(a))
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

class B1CharacterSwapEasyVersion {
public:
	void solve(istream& cin, ostream& cout) {
        int k;
        cin >> k;
        while(k--){
            int n;
            string s , t;
            cin >> n >> s >> t;
            bool ans = true;
            int ch = 0;
            int idx = -1;
            for(int i = 0;i<n;i++){
                if(ch > 2){
                    ans = false;
                    break;
                }
                if(s[i] != t[i]){
                    ++ch;
                    if(idx == -1){
                        idx = i;
                    }else{
                        swap(s[idx],t[i]);
                        if(s != t){
                            ans = false;
                            break;
                        }
                    }
                }
            }
            if(ans && ch != 1 ){
                cout << "Yes\n";
            }else{
                cout << "No\n";
            }
        }
	}
};
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

class ACardGame {
public:
	void solve(istream& cin, ostream& cout) {
        int t;
        cin >> t;
        while(t--){
            int n , k1 , k2;
            cin >> n >> k1 >> k2;
            bool first = false;
            for(int i=0;i<k1;i++){
                int x;
                cin >> x;
                if(x ==n){
                    first = true;
                }
            }
            for(int i =0;i<k2;i++){
                int x;
                cin >> x;
            }
            if(first){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
	}
};
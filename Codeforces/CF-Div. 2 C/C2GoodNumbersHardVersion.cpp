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

vector<ll> pow3;
class C2GoodNumbersHardVersion {
public:
	void solve(istream& cin, ostream& cout) {
        for(ll i =1,j=1;i<=(ll)8e18;i*=3,j++){
            pow3.push_back(i);
        }
        int q;
        cin >> q;
        while(q--){
            ll n;
            cin >> n;
            ll sum = 0;
            int p2 = -1;
            for(int i =0;i<(int)pow3.size();i++){
                sum += pow3[i];
                if(sum >= n){
                    p2 = i;
                    break;
                }
            }
            ll mn = sum;
            for(int i = p2;i>=0;i--){
                if(sum - pow3[i] >= n){
                    sum -= pow3[i];
                    mn = sum;
                }
            }
            cout << mn << el;
        }
	}
};
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

int b[N];
class CAliceBobAndChocolate {
public:
	void solve(istream& cin, ostream& cout) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        if(n == 1){
            cout << 1 << ' ' << 0;
            return;
        }
        int alice=1 , bob =1;
        int p1= 0,p2 = n-1;
        int sumAlice = b[p1++] , sumBob = b[p2--];
        while(p1<=  p2){
            if(sumAlice <= sumBob){
                sumAlice += b[p1++];
                ++alice;
            }else if(sumBob < sumAlice){
                sumBob += b[p2--];
                ++bob;
            }
        }
        cout << alice << ' ' << bob << el;
	}
};
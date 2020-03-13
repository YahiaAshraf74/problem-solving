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

class APensAndPencils {
public:
	void solve(istream& cin, ostream& cout) {
        int t;
        cin >> t;
        while(t--){
            int a, b , c ,d ,k;
            cin >> a >> b >> c >> d >> k;
            int pen = ceil((long double)a/c);
            int penceil = ceil((long double) b /d);
            if(pen + penceil > k){
                cout << -1 << el;
            }else{
                cout << pen << ' ' << penceil << el;
            }
        }
	}
};
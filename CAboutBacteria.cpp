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

class CAboutBacteria {
public:
	void solve(istream& cin, ostream& cout) {
        ll k , b , n , t;
        cin >> k >> b >> n >> t;
        ll  m = 0, z =1;
        for(int i =0;i<n;i++){
            z = (z*k) + b;
            ++m;
            if(z > t){
                break;
            }
        }
        if(t >= z)
            m = n = 0;
        else
            --m;
        cout << n - m;
	}
};
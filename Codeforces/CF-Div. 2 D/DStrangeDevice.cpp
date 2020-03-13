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

class DStrangeDevice {
public:
	void solve(istream& cin, ostream& cout) {
        int n , k;
        cin >> n >> k;
        map<int,int> mp;
        for(int i = 1;i<=k+1;i++){
            cout << "? ";
            for(int j =1;j<=k+1;j++){
                if(i!=j)
                    cout << j << ' ';
            }
            cout << endl;
            int a;
            cin >> a >> a;
            mp[a]++;
        }
        cout << "! " << mp.rbegin()->second << endl;
	}
};
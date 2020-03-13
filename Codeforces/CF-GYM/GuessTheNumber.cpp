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

class GuessTheNumber {
public:
	void solve(istream& cin, ostream& cout) {
        string s;
        int st = 1 , ed = (int)1e6;
        while(st < ed){
            int mid = (st+ed+1) / 2;
            cout << mid << endl;
            cin >> s;
            if(s == "<"){
                ed = mid -1;
            }else{
                st = mid;
            }
        }
        cout <<"! " << st << endl;
	}
};
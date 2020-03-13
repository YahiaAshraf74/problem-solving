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

int a;
string b;
bool lucky(string s){
    string l = "";
    for(int i =0;i<(int)s.size();i++){
        if(s[i] == '4' || s[i] == '7')
            l.push_back(s[i]);
    }
    return l == b;
}
class BLuckyMask {
public:
	void solve(istream& cin, ostream& cout) {
        cin >> a >> b;
        int bb = stoi(b);
        for(int i =a+1;i<=1e6;i++){
            if(lucky(to_string(i))){
                cout << i << el;
                return;
            }
        }
	}
};
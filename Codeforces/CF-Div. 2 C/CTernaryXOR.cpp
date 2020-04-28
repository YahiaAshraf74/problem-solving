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
#define el  '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define sz(a) (int)(a).size()
const long long N = (int) 2e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

class CTernaryXOR {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            int n;
            string s, a = "1", b = "1";
            cin >> n >> s;
            bool beDone = false;
            for (int i = 1; i < sz(s); i++) {
                if(s[i] == '0'){
                    a.push_back('0');
                    b.push_back('0');
                    continue;
                }
                if(s[i] == '2' && !beDone){
                    a.push_back('1');
                    b.push_back('1');
                }else if(s[i] == '2'){
                    a.push_back('0');
                    b.push_back('2');
                } 
                if(s[i] == '1' && !beDone){
                    a.push_back('1');
                    b.push_back('0');
                    beDone = true;
                }else if(s[i] == '1'){
                    a.push_back('0');
                    b.push_back('1');
                }
            }
            cout << a << el << b << el;
        }
    }
};
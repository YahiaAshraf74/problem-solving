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

class ACompetitiveProgrammer {
public:
	void solve(istream& cin, ostream& cout) {
	    int n ;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            int m = 0 , sum = 0 , y = 0;
            for (int j = 0; j < s.size(); j++) {
                if (m == 1 && (s[j] == '0')) {
                    y = 1;
                }
                if (s[j] == '0') {
                    m = 1;
                }
                if (s[j] == '2' || s[j] == '4' || s[j] == '6' || s[j] == '8') {
                    y = 1;
                }
                sum += s[j] - '0';
            }
            if (sum % 3 == 0 && m == 1 && y == 1) {
                cout << "red" << el;
            } else {
                cout << "cyan" << el;
            }
        }
    }
};
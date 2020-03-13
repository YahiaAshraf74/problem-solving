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

multiset<string> st[27];
class GAbbreviationsAndAcronyms {
public:
	void solve(istream& cin, ostream& cout) {
        string s;
        cin >> s;
        int n;
        cin >> n;
        string t;
        while(n--){
            cin >> t;
            st[t[0]-'A'].insert(t);
        }
        string ans = "";
        for(int i = 0;i<(int)s.size();i++){
            if(st[s[i]-'A'].empty()){
                cout << "Impossible\n";
                return;
            }
            ans += *(st[s[i]-'A'].begin()) + " ";
            st[s[i]-'A'].erase(st[s[i]-'A'].begin());
        }
        cout << ans << el;
	}
};
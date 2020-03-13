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
#define el    '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 1e4 + 74, OO = 0x3f3f3f3f;

int n;
char s[11][N];
vector<string> strs;
class BSecretCombination {
public:
    void solve(istream &cin, ostream &cout) {
        cin >> n;
        cin >> s[0];
        for (int i = 1; i < 10; i++) 
            for (int j = 0; j < n; j++) 
                s[i][j] = (((s[0][j] - '0') + i) % 10 + '0');
	    for(int i =0;i<10;i++){
	        deque<char> dq;
	        for(int j = 0;j<n;j++)
	            dq.push_back(s[i][j]);
	        for(int j = 0;j<n;j++){
	            dq.push_front(dq.back());
	            dq.pop_back();
	            string temp;
	            for(int p=0;p<n;p++){
	                temp.push_back(dq[p]);
	            }
	            strs.push_back(temp);
	        }
	    }
	    string mn = strs[0];
	    for(int i = 1;i<(int)strs.size();i++)
	        mn = min(mn,strs[i]);
	    cout << mn << el;
	    strs.clear();
    }
};
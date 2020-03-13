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
#define all(v)  ((v).begin()),((v).end())
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

string b;
unordered_map< char, set<int> > mp;
int get(int l, int r, char c){
    auto a = mp[c].lower_bound(l);
    auto b = mp[c].upper_bound(r);
    if(a!=b)
        return 1;
    else
        return 0;
}
class DDistinctCharactersQueries {
public:
	void solve(istream& cin, ostream& cout) {
        cin >> b;
        for (int i=0; i<(int)b.size(); ++i)
            mp[b[i]].insert(i);
        int q;
        cin >> q;
        while(q--){
            int type;
            cin >> type;
            if(type == 1){
                int pos;
                char c;
                cin >> pos >> c;
                --pos;
                mp[b[pos]].erase(pos);
                b[pos] = c;
                mp[b[pos]].insert(pos);
            }else{
                int l , r;
                cin >> l >> r;
                --l,--r;
                int ans = 0;
                for(char c = 'a';c<='z';c++){
                    ans += (get(l,r,c) > 0);
                }
                cout << ans << el;
            }
        }
        mp.clear();
	}
};
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
using namespace std;
#define el	'\n'
#define ll long long
#define clr(a,b)memset(a,b,sizeof(a))
#define all(v)  ((v).begin()),((v).end())
const int N = 1e3 + 3, OO = 0x3f3f3f3f;

string b;
string ans ;
int mem[N][N];
vector<pair<int,char>> upd;
int dp(int i,int j){
    if(i >= j){
        return 0;
    }
    int &ret = mem[i][j];
    if(~ret)
        return ret;
    if(b[i] == b[j])
        return ret = dp(i+1,j-1);
    int c1 = dp(i,j-1)+1;
    int c2 = dp(i+1,j)+1;
    ret = min(c1,c2);
    return ret;
}
void build(int i,int j){
    if(i >= j){
        if (i==j)
            ans.push_back(b[i]);
        return;
    }
    int optimal = dp(i,j);
    int c1 = dp(i,j-1)+1;
    int c2 = dp(i+1,j)+1;
    if(b[i] == b[j]) {
        ans.push_back(b[i]);
        build(i+1,j-1);
        ans.push_back(b[i]);
    }else if(optimal == c1){
        ans.push_back(b[j]);
        build(i,j-1);
        ans.push_back(b[j]);
    }else if(optimal == c2){
        ans.push_back(b[i]);
        build(i+1,j);
        ans.push_back(b[i]);
    }
}
class MakePalindrome {
public:
    void solve(istream& cin, ostream& cout) {
        while(cin >> b){
            clr(mem,-1);
            ans.clear();
            int res = dp(0, (int)b.size() - 1);
            cout << res << ' ';
            build(0, (int)b.size() - 1);
            cout << ans << el ;
        }
    }
};
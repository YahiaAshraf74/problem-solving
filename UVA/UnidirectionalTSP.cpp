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
#define el    '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define all(v)  ((v).begin()),((v).end())
const int N = 1e2 + 3, OO = 0x3f3f3f3f;

int n, m;
int grid[13][N];
pair<int,vector<int>> mem[11][N];
int v(int i) {
    return (i < 0) ? n - 1 : (i >= n) ? 0 : i;
}
pair<int,vector<int>> dp(int i, int j) {
    if (j == m)
        return {0,{}};
    pair<int,vector<int>> &ret = mem[i][j];
    if (~ret.first)
        return ret;
    pair<int,vector<int>> ch1 , ch2 , ch3 , ch4;
    ch1.first = OO;
    if(j ==0 && i < n-1){
        ch1 = dp(v(i+1),j);
    }
    ch2 = dp(v(i - 1), j + 1);
    ch2.first += grid[i][j];
    ch2.second.push_back(i);

    ch3 = dp(i,j+1);
    ch3.first += grid[i][j];
    ch3.second.push_back(i);

    ch4 = dp(v(i+1),j+1);
    ch4.first += grid[i][j];
    ch4.second.push_back(i);
    ret = min(min(ch1,ch2), min(ch3, ch4));
    return ret;
}
void init(int n,int m){
    for(int i =0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            mem[i][j].first = -1;
            mem[i][j].second.clear();
        }
    }
    clr(grid,0);
}
/*
vector<int> build(int i,int j){
    if(j ==m)
        return {0};
    vector<int> &ret = mem2[i][j];
    if(ret.size() > 0)
        return ret;
    vector<int> ch1 , ch2 , ch3 , ch4;
    int c1 , c2 ,c3 ,c4;
    if(j ==0 && i < n-1){
        c1 = dp(i+1,j);
    }
    c2 = dp(v(i - 1), j + 1);
    c3 = dp(i, j + 1);
    c4 = dp(v(i + 1), j + 1);
    int optimal = dp(i,j);
    if(c1 == optimal){
        ch1 = ret;
        ch1.push_back(i+1);
    }
}

void build(int i, int j) {
    if (j == m)
        return;
    int ch1 = OO , ch2 ,ch3 ,ch4;
    if(j==0 && i < n-1){
        ch1 = dp(i+1,j);
    }
    ch2 = dp(v(i - 1), j + 1)+ grid[i][j];
    ch3 = dp(i, j + 1)+ grid[i][j];
    ch4 = dp(v(i + 1), j + 1)+ grid[i][j];
    int optimal = dp(i, j);
    int mn[5] ={OO,OO,OO,OO,OO};
    if(ch1 == optimal){
        mn[1] = v(i+1);
    }
    if(ch2 == optimal){
        mn[2] = v(i-1);
    }
    if(ch3 == optimal){
        mn[3] = i;
    }
    if(ch4 == optimal){
        mn[4] = v(i+1);
    }
    int mnCh  , mn2 = OO;
    for(int c =1;c<=4;c++){
        if(mn2 > mn[c]){
            mn2 = mn[c];
            mnCh = c;
        }
    }
    if(1 == mnCh){
//        path.push_back(mn2);
        build(i+1,j);
    }else if(2 == mnCh){
        path.push_back(mn2);
        build(v(i-1),j+1);
    }else if(3 ==mnCh){
        path.push_back(mn2);
        build(i,j+1);
    }else if(4 == mnCh){
        path.push_back(mn2);
        build(v(i+1),j+1);
    }
}

*/

class UnidirectionalTSP {
public:
    void solve(istream &cin, ostream &cout) {
//        freopen("output.txt","w",stdout);
        while (cin >> n >> m) {
            init(n,m);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cin >> grid[i][j];
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m/2;j++){
                    swap(grid[i][j],grid[i][m-j-1]);
                }
            }
            pair<int,vector<int>> ans = dp(0,0);
//            reverse(all(ans.second));
            for(int i =0;i<ans.second.size();i++){
                cout << ans.second[i]+1 << " \n"[i==ans.second.size()-1];
            }
            cout <<  ans.first << el;
        }
    }
};
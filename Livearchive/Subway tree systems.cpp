/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author YahiaAshraf74
 */

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
const int N = 3e3 + 74, OO = 0x3f3f3f3f;

string s , s2;
vector<vector<int>> adj;
string canoincal(int u , int par){
    vector<string> children;
    for(int i =0;i<(int)adj[u].size();i++){
        if(adj[u][i] != par)
            children.push_back(canoincal(adj[u][i],u));
    }
    string rep = "(";
    sort(all(children));
    for(int i = 0;i<(int)children.size();i++){
        rep += children[i];
    }
    rep += ")";
    return rep;
}
void getAdj(string s){
    adj = vector<vector<int>>(s.size() + 1);
    stack<int> st;
    int node = 1;
    st.push(node);
    for(int i = 0;i<(int)s.size();i++){
        if(s[i] == '1'){
            st.pop();
        }else{
            adj[st.top()].push_back(++node);
            st.push(node);
        }
    }
}

class SubwayTreeSystems {
public:
	void solve(istream& cin, ostream& cout) {
        int T;
        cin >> T;
        while(T--){
            cin >> s >> s2;
            getAdj(s);
            string cmp = canoincal(1,0);
            getAdj(s2);
            string cmp2 = canoincal(1,0);
            if(cmp == cmp2){
                cout << "same\n";
            }else{
                cout << "different\n";
            }
        }
	}
};

int main() {
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	SubwayTreeSystems solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}

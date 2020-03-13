#include <bits/stdc++.h>
using namespace std;
#define el      	'\n'
#define ft 			first
#define sd 			second
#define mp(x,y)  	make_pair((x),(y))
#define pb(x)    	push_back((x))
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((int) (x).size())
#define lp(i,n) 	for(int i=0;i<(int)n;i++)
#define lpv(i,a,n) 	for(int i=a;i<=(int)n;i++)
#define clr(a,b)	memset(a,b,sizeof(a))
typedef long long ll;
void Yahia74() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
const int N = 5e2 + 4, M = 1e5 + 74, OO = 0x3f3f3f3f;

//unordered_map<pair<int,int>,bool> vis1 ;
set<pair<int, int> > vis;
		vector<int> mov;
string movName[6] = { "fill A", "fill B", "empty A", "empty B", "pour A B","pour B A", };
bool markVisited(pair<int, int> temp) {
	if (vis.find(temp) == vis.end()) {
		vis.insert(temp);
		return true;
	}
	return false;
}
int main() {
	Yahia74();
	int n, m, t;
	while (cin >> n >> m >> t) {
		queue<pair<pair<int, int>, vector<int>> > q;
		vis.clear();
		mov.clear() ;
		mov.pb(1);
		q.push( { { n, 0 }, mov });
		mov.pop_back();
		mov.pb(2);
		q.push( { { 0, m }, mov });
		mov.pop_back();
		bool found = false;
		while (!q.empty() && !found) {
			int sz = q.size();
			while (sz--) {
				pair<int, int> cur = { q.front().ft.ft, q.front().ft.sd };
				vector<int> mov2 = q.front().sd ;
				if (cur.ft == t || cur.sd == t) {
					lp(i,sz(mov2)){
						cout << movName[mov2[i]-1] << el ;
					}
					cout << "success" << el ;
					found = true;
					break;
				}
				q.pop();
				if (markVisited(cur)) {
					mov2.pb(1);
					q.push( { { n, cur.sd }, mov2 });
					mov2.pop_back();
					mov2.pb(2);
					q.push( { { cur.ft, m }, mov2 });
					mov2.pop_back();
					mov2.pb(3);
					q.push( { { 0, cur.sd }, mov2 });
					mov2.pop_back();
					mov2.pb(4);
					q.push( { { cur.ft, 0 }, mov2 });
					mov2.pop_back();
					mov2.pb(5);
					q.push({ { max(0, cur.ft - (m - cur.sd)), min(cur.sd + cur.ft, m) }, mov2 });
					mov2.pop_back();
					mov2.pb(6);
					q.push({ { min(cur.sd + cur.ft, n), max(0,cur.sd - (n - cur.ft)) }, mov2 });
					mov2.pop_back();
				}
			}
		}
	}
	return 0;
}

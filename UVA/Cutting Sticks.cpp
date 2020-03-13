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
const int N = 1e4 + 5, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

bool a[1005];
int mem[1005][1005];
int solve(int st , int ed ) {
	if (ed == st)
		return 0;
	if (mem[st][ed] != -1)
		return mem[st][ed];
	int ret = OO;
	for (int i = st ; i < ed; i++) {
		if (a[i])
			ret = min(ret, solve(i+1, ed) + solve(st, i) + (ed - st+1));
	}
	if (ret == OO)
		ret = 0;
	mem[st][ed] = ret;
	return mem[st][ed] ;
}
int main() {
	Yahia74();
	int len;
	while (cin >> len) {
		if (!len)
			break;
		clr(mem, -1);
		clr(a,false);
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			int x;
			cin >> x;
			a[x] = true;
		}
		cout << "The minimum cutting is " << solve(1,len) << "." << el;
	}
	return 0;
}

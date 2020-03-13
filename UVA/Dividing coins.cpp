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
const int N = 1e2 + 5, M = 1e5 + 5, OO = 0x3f3f3f3f;

int n ;
int a[N];
int mem[N][M] ;
int mn = OO;
int solve(int i = 0 ,int dif = 50000){
	if(i==n){
		mn = min(mn , abs(dif-50000)) ;
		return 0 ;
	}
	int &ret = mem[i][dif] ;
	if(~ret)
		return ret ;
	ret = OO ;
	ret = min(solve(i+1,dif+a[i]) , solve(i+1,dif-a[i])) ;
	return ret ;
}
int main() {
	Yahia74();
	int T ;
	cin >> T ;
	while(T--){
		mn = OO ;
		cin >>n ;
		for (int i = 0; i < n; ++i) {
			cin >> a[i] ;
		}
		clr(mem,-1) ;
		int sol = solve() ;
		cout << mn << el ;
	}
	return 0;
}

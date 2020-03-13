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
const int N = 1e4 + 5, M = 1e5 + 5, OO = 0x3f3f3f3f;

int n ,k ;
int a[N];
//int mem[N][N] ;
int solve(int i = 0 , int j = n -1 , int cnt = 0){
	if(i>=j)
		return cnt ;
	if(cnt > k)
		return OO ;
// 	int &ret = mem[i][j] ;
// 	if(ret>k)
// 		return OO;
//	if(~ret)
//		return ret ;
//	ret = OO ;
	if(a[i] == a[j]){
		return solve(i+1,j-1,cnt) ;
	}
	return min(solve(i,j-1,cnt+1),solve(i+1,j,cnt+1) );
}

int main() {
	Yahia74();
	int T , cases = 0;
	cin >> T ;
	while(T--){
//		clr(mem,-1) ;
		cin >>n >> k;
		for (int i = 0; i < n; ++i) {
			cin >> a[i] ;
		}
		int sol = solve(0,n-1) ;
		cout << "Case "<<++cases<< ": " ;
		if(sol>k){
			cout << "Too difficult";
		}else if(sol == 0){
			cout << "Too easy";
		}else{
			cout << sol ;
		}
		cout << el ;
	}
	return 0;
}

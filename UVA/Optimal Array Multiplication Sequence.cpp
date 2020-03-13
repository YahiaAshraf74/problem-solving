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
const int N = 1e4 + 5, M = 1e5 + 74, OO = 0x3f3f3f3f;

int n , idx , tk;
pair<int,int> mat[11] ;
int mem[11][11] ;
int solve(int i = 0 , int j = n-1){
	if(i==j)
		return 0 ;
	int &ret = mem[i][j] ;
	if(~ret)
		return ret ;
	ret = OO ;
	for(int k = i ; k < j ;k++){
		ret = min(ret , solve(i,k) + solve(k+1,j) + mat[i].ft*mat[j].sd*mat[k+1].ft ) ;
	}
	return ret ;
}
void build(int i = 0 ,int j = n-1){
	if(i==j){
		cout << 'A' << ++idx ;
		return ;
	}
	for (int k = i; k < j; ++k) {
		int ch1 = solve(i,k) + solve(k+1,j) + mat[i].ft*mat[j].sd*mat[k+1].ft ;
		if(solve(i,j) == ch1){
			cout << '(' ;
			build(i,k) ;
			cout << " x " ;
			build(k+1,j) ;
			cout << ')' ;
			return ;
		}
	}
}
int main() {
	Yahia74();
	while(cin>> n){
		if(!n) break ;
		clr(mem,-1) ;
		idx = 0 ;
		for (int i = 0; i < n; ++i) {
			cin>> mat[i].ft >> mat[i].sd ;
		}
		cout << "Case " << ++tk << ": ";
		solve() ;
		build() ;
		cout << el ;
	}
	return 0;
}

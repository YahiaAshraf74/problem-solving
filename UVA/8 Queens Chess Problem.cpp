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
	cout << fixed << setprecision(8);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int T , posX , posY , numOfPos;
vector < pair<int ,int > > ans ;
vector< vector<int> > sortedAns ;
bool visC[8] ,visD1[17] , visD2[17] , vis[8][8];
void gen(int c) {
	if (c==8) {
		//base case
		lp(i,8)lp(j,8) if (vis[j][i]) ans.pb(mp(j+1,i+1));
	}else {
		lp(r,8){
			if (!visC[r] && !visD1[r+c] && !visD2[8+(r-c)] ){
				visC[r] = visD1[r+c] = visD2[8+(r-c)] = vis[c][r]  = true ;
				gen(c+1) ;
				visC[r] = visD1[r+c] = visD2[8+(r-c)] = vis[c][r] = false ;
			}
		}
	}
}
int main() {
	Yahia74();
	gen(0);
//	cout << sz(ans) ;
//	lp(i,sz(ans)){
//		if (i%8==0) cout << "\n*******************" << el ;
//		cout << ans[i].ft << " " << ans[i].sd << el ;
//	}
	cin >> T ;
	lp(tc,T){
		cin >> posX >> posY ;
		cout << "SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n"  ;
		numOfPos = 0 ;
		sortedAns.clear() ;
		lp(i,sz(ans)){
			if (ans[i].ft == posX && ans[i].sd == posY) {
				int idx = 0 ;
				vector<int> temp ;
				lpv(j,(i/8)*8,(i/8)*8+7){
					if (ans[j].ft == posX &&ans[j].sd == posY )
						idx = j;
					temp.pb(ans[j].ft);
				}
				sortedAns.pb(temp) ;
				while(idx%8 != 0)
					++idx ;
				i = idx ;
			}
		}
		sort(all(sortedAns)) ;
		lp(i,sz(sortedAns)){
			if (numOfPos < 9) cout << " " ;
			cout << ++numOfPos << "     ";
			lp(j,sz(sortedAns[i])){
				cout << " " << sortedAns[i][j] ;
			}
//			if (i != sz(sortedAns)-1 )
			cout << el ;
		}
		if (tc != T-1)cout << el ;

	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define el      	'\n'
#define ft 			first
#define sd 			second
#define mp(x,y)  	make_pair((x),(y))
#define pb(x)    	push_back((x))
#define all(v)  	((v).begin()),((v).end())
#define rall(v)		v.rbegin(),v.rend()
#define sz(x)  		((int) (x).size())
#define lp(i,n) 	for(int i=0;i<(int)n;i++)
#define lpv(i,a,n) 	for(int i=a;i<=(int)n;i++)
#define clr(a,b)	memset(a,b,sizeof(a))
typedef long long ll;
void YAHIA() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);  //freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int nums[5], ck;
bool vis[5], flag;

int evaluate(char *exp) {
	int res = exp[0] - '0';
	for (int i = 1; exp[i]; i += 2) {
		// The next character must be an operator, and
		// next to next an operand
		char opr = exp[i], opd = exp[i + 1];
		// If next to next character is not an operand
		// Update result according to the operator
		if (opr == '+')
			res += opd - '0';
		else if (opr == '-')
			res -= opd - '0';
		else if (opr == '*')
			res *= opd - '0' ;
	}
	return res;
}
void backTrack(int cnt, string opr, vector<int> & chosen , bool notFirst) {
	if (flag )
		return ;
	if (cnt == 5) {
		 char exp[11] ;
		 exp[0] = chosen[0] + '0';
		 exp[2] = chosen[1] + '0';
		 exp[4] = chosen[2] + '0';
		 exp[6] = chosen[3] + '0';
		 exp[8] = chosen[4] + '0';
		 exp[1] = opr[0] ;
		 exp[3] = opr[1] ;
		 exp[5] = opr[2] ;
		 exp[7] = opr[3] ;
		 if (evaluate(exp) == 23){
			 flag = true ;
			 return ;
		 }
	} else {
		lp(i,5) if (!vis[i]) {
				vis[i] = true;
				chosen.pb(nums[i]);
				if (notFirst){
					backTrack(cnt + 1, opr + "+", chosen,1);
					backTrack(cnt + 1, opr + "-", chosen,1);
					backTrack(cnt + 1, opr + "*", chosen,1);
				}else {
					backTrack(cnt + 1, opr , chosen,1);
				}
				chosen.pop_back();
				vis[i] = false;
			}
		}
}
int main() {
	YAHIA();
	while (true) {
		ck = 0;
		flag = false;
		clr(vis,0);
		lp(i,5)
			cin >> nums[i], ck += nums[i];
		if (ck==0)
			break;
		vector<int> ans;
		backTrack(0, "", ans , 0 );
		if (flag)
			cout << "Possible\n";
		else
			cout << "Impossible\n";
	}
	return 0;
}

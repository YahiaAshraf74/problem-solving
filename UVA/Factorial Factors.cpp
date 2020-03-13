#include <bits/stdc++.h>
using namespace std;
#define el      	'\n'
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((int) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
typedef long long ll;
void Yahia74() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
const int N = 1e6 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

const int MAXP = 32000; // 31623

vector<int> primes;
int dp[N];
void sieve() {
	vector<int> p;
	vector<bool> isp(MAXP, 1);
	isp[0] = isp[1] = 0;
	for (int i = 2; i * i < MAXP; i++)
		if (isp[i])
			for (int j = i * i; j < MAXP; j += i)
				isp[j] = 0;
	for (int i = 0; i < MAXP; i++)
		if (isp[i])
			primes.push_back(i);
}

int facto(int n) {
	int cnt = 0;
	for (ll i = 0; i < (int)primes.size() && (ll)primes[i] * primes[i] <= (ll)n; i++) {
		while(n%primes[i] == 0){
			n /= primes[i];
			++cnt;
		}
	}
	if (n > 1)
		cnt++;
	return cnt;
}
int main() {
	Yahia74();
	sieve();
	for(int i=1;i<=1e6;i++)
		dp[i] = dp[i-1] + facto(i);
	int n;
	while(cin >> n){
		cout << dp[n] << el;
	}
	return 0;
}

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
#include <iomanip> 
using namespace std;
#define el	'\n'
#define ll long long
#define clr(a,b)memset(a,b,sizeof(a))
#define all(v)  ((v).begin()),((v).end())
const int N = (int)4e4, OO = 0x3f3f3f3f;

int countDigit(ll n) {
    int res = 0;
    while (n) { res++; n /= 10; }
    return res;
}
ll sum[N+1];
class E1NumericalSequenceEasyVersion {
public:
	void solve(istream& cin, ostream& cout) {
//	    freopen("output.txt","w",stdout);
        ll num =0;
        string digits = "";
        for (int i = 1; i < N; i++) {
            num += countDigit(i);
            sum[i] = sum[i - 1] + num;
            digits += to_string(i);
        }
        int T;
        cin >> T;
        while(T--){
            int n;
            cin >> n;
            int st = 1, ed = N - 1, ans = N - 1;
            while (st <= ed) {
                int mid = (st + ed) >> 1;
                if (sum[mid] >= n)
                    ed = mid - 1, ans = min(ans, mid);
                else
                    st = mid + 1;
            }
            cout << digits[n - sum[ans - 1] - 1] << el;
        }
	}
};
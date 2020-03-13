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
#define el    '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 1e5 + 74, OO = 0x3f3f3f3f;
//const int MAXP = 320000; // 31623
//
//
//
//vector<int> sieve() {
//    vector<int> p;
//    vector<bool> isp(MAXP, 1);
//    isp[0] = isp[1] = 0;
//    for (int i = 2; i * i < MAXP; i++)
//        if (isp[i])
//            for (int j = i * i; j < MAXP; j += i)
//                isp[j] = 0;
//    for (int i = 0; i < MAXP; i++)
//        if (isp[i])p.push_back(i);
//    return p;
//} // array size 3432
//
//vector<pair<int, int> > facto(int n, const vector<int> &primes) {
//    vector<pair<int, int> > result;
//    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++) {
//        if (n % primes[i] == 0) {
//            int cnt = 0;
//            while (n % primes[i] == 0) {
//                n /= primes[i];
//                cnt++;
//            }
//            result.push_back({primes[i], cnt});
//        }
//    }
//    if (n > 1) {
//        result.push_back({n, 1});
//    }
//    return result;
//}
//
////set<int> temp;
//vector<int> adj[int(2e6 + 100)];
//int ii = 2;
//
//void bt(int index, int num, const vector<pair<int, int> > &factors) {
//    if (index == factors.size()) {
////        collector[num]++;
//    } else {
//        int x = factors[index].first;
//        int cnt = factors[index].second;
//        int accu = 1;
//        bt(index + 1, num, factors);
//        for (int i = 0; i < cnt; i++) {
//            accu *= x;
////            adj[ii].push_back(num);
//            adj[ii].push_back(num * accu);
//            if (num * accu == ii)
//                adj[ii].pop_back();
//            bt(index + 1, num * accu, factors);
//        }
//    }
//}
//
//void process(int n, const vector<int> &primes) {
//    vector<pair<int, int> > factors = facto(n, primes);
//    bt(0, 1, factors);
//}

class DAlmostAllDivisors {
public:
    void solve(istream &cin, ostream &cout) {
//        vector<int> primes = sieve();
//        for (ii = 2; ii <= (int) 2e6 + 5; ii++)
//            process(ii, primes);
//        int T;
//        cin >> T;
//        while (T--) {
//            int n;
//            cin >> n;
//            for (int i = 0; i < n; ++i) {
//                cin >> divv[i];
//            }
//            sort(divv, divv + n);
//            int ans = OO;
//            for (int j = 2; j <= (int) 2e6 + 5; j++) {
//                if ((int) adj[j].size() == n) {
//                    bool flag = false;
//                    sort(all(adj[j]));
//                    for (int i = 0; i < n; i++) {
//                        if (adj[j][i] != divv[i]) {
//                            flag = true;
//                            break;
//                        }
//                    }
//                    if(!flag)
//                        ans = min(j,ans);
//                }
//            }
//            if(ans == OO){
//                cout << -1 << el;
//            }else {
//                cout << ans << el;
//            }
//        }
        int div[308]={};
        int t;
        cin >> t;
        while(t--){
            int n;
            cin >> n;
            for(int i =0;i<n;i++)
                cin >> div[i];
            sort(div,div+n);
            ll num = (ll)div[0] * div[n-1];
            vector<int> div2;
            for(ll i = 2;(ll)i*i<=num;i++){
                if(num%i == 0){
                    div2.push_back(i);
                    if(num/i != i)
                        div2.push_back(num/i);
                }
            }
            sort(all(div2));
            bool flag = false;
            if(n != div2.size()){
                cout << -1 << el;
                continue;
            }
            for(int i =0;i<n;i++){
                if(div[i] != div2[i]){
                    flag = true;
                    break;
                }
            }
            if(flag){
                cout << -1 << el;
            }else{
                cout << num << el;
            }
        }
    }
};
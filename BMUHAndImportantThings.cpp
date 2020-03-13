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
#define el	'\n'
#define ll long long
#define clr(a,b)memset(a,b,sizeof(a))
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 2e3 + 74, OO = 0x3f3f3f3f;

pair<int,int> a[N];
class BMUHAndImportantThings {
public:
	void solve(istream& cin, ostream& cout) {
        int n;
        cin >> n;
        for(int i =0;i<n;i++){
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a,a+n);
        int cnt = 0;
        for(int i =0;i<n-1;i++){
            if(a[i].first == a[i+1].first){
                cnt++;
            }
        }
        if(cnt < 2){
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        for(int i =0;i<n;i++){
            cout << a[i].second + 1 << ' ';
        }
        cout << el;
        bool flag = false;
        for(int i =0;i<n-1;i++){
            if(a[i].first == a[i+1].first && !flag){
                flag = true;
                swap(a[i].second , a[i+1].second);
                for(int i =0;i<n;i++){
                    cout << a[i].second + 1 << ' ';
                }
                cout << el;
            }else if(a[i].first == a[i+1].first && flag){
                swap(a[i].second , a[i+1].second);
                for(int i =0;i<n;i++){
                    cout << a[i].second + 1 << ' ';
                }
                break;
            }
        }
	}
};
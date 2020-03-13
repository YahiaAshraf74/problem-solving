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
#define el    '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

int a[302][302];

class CLabs {
public:
    void solve(istream &cin, ostream &cout) {
        int n;
        cin >> n;
        int cnt = n*n;
        for (int j = 0; j < n; j++) {
            if(j%2==0){
                for(int i =0;i<n;i++){
                    a[i][j] = cnt--;
                }
            }else{
                for(int i = n -1 ;i>=0;i--){
                    a[i][j] = cnt--;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << a[i][j] << ' ';
            }
            cout << el;
        }
    }
};
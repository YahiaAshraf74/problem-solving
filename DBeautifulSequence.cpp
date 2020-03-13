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
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

class DBeautifulSequence {
public:
	void solve(istream& cin, ostream& cout) {
        int a , b ,c ,d;
        cin >> a >> b >> c >> d;
        if(d<=c && a <= b && abs((c-d)-(b-a)) <= 1){
            cout << "YES\n";
            vector<int> v ,v2;
            while(true){
                if(a == 0)
                    break;
                v.push_back(0);
                v.push_back(1);
                --b;
                --a;
            }
            while(true){
                if(d == 0)
                    break;
                v.push_back(2);
                v.push_back(3);
                --c;
                --d;
            }
            if(b > c){
                while(true){
                    if(b == 0 && c == 0)
                        break;
                    if(b)
                        v2.push_back(1) , b--;
                    if(c)
                        v2.push_back(2) , c--;
                }
                for(int i : v2)
                    cout << i << ' ';
                for(int i : v)
                    cout << i << ' ';
            }else{
                while(true){
                    if(b == 0 && c == 0)
                        break;
                    if(c)
                        v2.push_back(2) , c--;
                    if(b)
                        v2.push_back(1) , b--;
                }
                for(int i : v)
                    cout << i << ' ';
                for(int i : v2)
                    cout << i << ' ';
            }
        }else{
            if(a == 0 && b == 0 && abs(c-d) <= 1){
                cout << "YES\n";
                if(c>d){
                    while(true){
                        if(c == 0 && d == 0)
                            break;
                        if(c)
                            cout << 2 << ' ' , c--;
                        if(d)
                            cout << 3 << ' ' , d--;
                    }
                }else{
                    while(true){
                        if(c == 0 && d == 0)
                            break;
                        if(d)
                            cout << 3 << ' ' , d--;
                        if(c)
                            cout << 2 << ' ' , c--;
                    }
                }
                return;
            }
            if(c == 0 && d == 0 && abs(a-b) <= 1){
                cout << "YES\n";
                if(a>b){
                    while(true){
                        if(a == 0 && b == 0)
                            break;
                        if(a)
                            cout << 0 << ' ' , a--;
                        if(b)
                            cout << 1 << ' ' , b--;
                    }
                }else{
                    while(true){
                        if(a == 0 && b == 0)
                            break;
                        if(b)
                            cout << 1 << ' ' , b--;
                        if(a)
                            cout << 0 << ' ' , a--;
                    }
                }
                return;
            }
            cout << "NO\n";
        }
	}
};
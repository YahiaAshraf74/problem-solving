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
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

class CRobotBreakout {
public:
	void solve(istream& cin, ostream& cout) {
        int q;
        cin >> q;
        while(q--){
            int n;
            cin >> n;
            int fromX = 1e5, toX = -1e5 , fromY = 1e5 , toY = -1e5;
            for(int i=0;i<n;i++){
                int x , y ,f1 , f2 ,f3,f4;
                cin >> x >> y >> f1 >> f2 >> f3 >> f4;
                if(!f1){
                    toX = max(toX,x);
                }
                if(!f2){
                    fromY = min(fromY,y);
                }
                if(!f3){
                    fromX = min(fromX,x);
                }
                if(!f4){
                    toY = max(toY,y);
                }
            }
            if(toX>fromX||toY>fromY)
                cout << 0 << el;
            else
                cout << "1 " << toX << " " << toY << el;
        }
	}
};
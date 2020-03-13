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
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

class ADawidAndBagsOfCandies {
public:
	void solve(istream& cin, ostream& cout) {
        int a , b ,c ,d;
        cin >> a >> b >> c >> d;
        int sum = a+b+c+d;
        if(sum&1){
            cout << "NO";
            return;
        }
        sum /= 2;
        if(a+b == sum || a+c == sum || a+d == sum || b+c == sum || b+d ==sum || c+d == sum || a+b+c == sum || a+b+d == sum || b+c+d == sum || a+c+d == sum){
            cout << "YES" << el;
        }else{
            cout << "NO" << el;
        }
	}
};
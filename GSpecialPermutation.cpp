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
#include <numeric>
#include <assert.h>
using namespace std;
#define el  '\n'
#define ll long long
#define clr(a,b)memset(a,b,sizeof(a))
#define sz(a) (int)(a).size()
const long long N = (int)2e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

class GSpecialPermutation {
public:
	void solve(istream& cin, ostream& cout) {
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            int n;
            cin >> n;
            n -= 4;
            if(n < 0){
                cout << -1 << el;
                continue;
            }
            deque<int> dq;
            dq.push_back(2);
            dq.push_back(4);
            dq.push_back(1);
            dq.push_back(3);
            int number = 5;
            bool parity = true;
            while(n--){
                if(parity == true){
                    dq.push_back(number++);
                    parity = false;
                }else{
                    dq.push_front(number++);
                    parity = true;
                }
            }
            for(int i : dq){
                cout << i << ' ';
            }
            cout << el;
        }
	}
};
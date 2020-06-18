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
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using max_heap = priority_queue<T, vector<T>, less<T>>;

class BTwoArraysAndSwaps {
public:
    void init(){

    }

	void solve(istream& cin, ostream& cout) {
        init();
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            int n,k;
            cin >> n >> k;
            vector<int> v(n) , v2(n);
            min_heap<int> mnHeap;
            max_heap <int> mxHeap;
            int sum = 0;
            for(int &num : v){
                cin >> num;
                mnHeap.push(num);
                sum += num;
            }
            for(int &num : v2){
                cin >> num;
                mxHeap.push(num);
            }
            while(mnHeap.size()){
                int mn = mnHeap.top() , mx = mxHeap.top();
                mnHeap.pop() , mxHeap.pop();
                if(mx > mn && k){
                    sum -= mn;
                    sum += mx;
                    --k;
                }else{
                    break;
                }
            }
            cout << sum << el;
        }
	}
};
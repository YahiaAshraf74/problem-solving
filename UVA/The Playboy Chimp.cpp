#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q, x, i;
    int arr[50074];
    cin >> n ;
    for(i = 0; i < n; i++)
        cin>>arr[i] ;
    vector<int> v(arr, arr+n);
    vector<int>::iterator low, up;
    cin>>q ;
    while(q--) {
        cin >> x ;
        low = lower_bound(v.begin(), v.end(), x);
        up  = upper_bound(v.begin(), v.end(), x);
        if(low-v.begin() == 0)
            cout<<"X " ;
        else
            cout<<*--low<<" ";
        if(up-v.begin() == n)
            cout<<"X\n";
        else
            cout<<*up<<"\n";
    }

    return 0;
}

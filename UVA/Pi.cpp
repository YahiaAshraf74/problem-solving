#include <bits/stdc++.h>

using namespace std;

int GCD (int a, int b ) {
    if (b==0) return a ;
    return GCD(b,a%b) ;
}

int main(){
    int n  ;
    while (cin >> n && n ) {
        int arr[74] ,cnt =0  ;
        memset(arr,0,sizeof(arr));
        for (int i = 0 ; i< n ;i++) cin >> arr[i] ;
        for (int i = 0 ; i< n ;i++)
            for (int j = i+1 ; j< n ;j++)
                if ( GCD(arr[i],arr[j]) == 1 )++cnt ;
        if (!cnt){ cout<< "No estimate for this data set.\n" ; }
        else printf("%0.6f\n",sqrt(6.000000*(n*(n-1)/2)/cnt));
    }
    return 0;
}

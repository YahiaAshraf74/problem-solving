#include <iostream>

using namespace std;

int main()
{
    int  c   ;
    long long n , m , i ,j  ;
    cin>>n>>m>>c ;
    long long arr[n][m]  ;
    arr[0][0] = c ;
    for ( i = 0 ; i<n ; i++){
        for ( j = 0 ;j<m ;j++){
            if (c == 1){
                if ( (i+j)%2 == 0 ){
                    arr[i][j] = 1 ;
                }
                if ( (i+j)%2 == 1 ){
                    arr[i][j] = 0 ;
                }
            }
            if (c == 0){
                if ( (i+j)%2 == 0 ){
                    arr[i][j] = 0 ;
                }
                if ( (i+j)%2 == 1 ){
                    arr[i][j] = 1 ;
                }
            }
        }
    }
    for ( i = 0 ; i<n ; i++){
        for ( j = 0 ;j<m ;j++){
            cout<<arr[i][j]<<"  " ;
        }
        cout<<endl;
    }
    return 0;
}

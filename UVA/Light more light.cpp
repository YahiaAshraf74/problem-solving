#include <iostream>
#include <math.h>

using namespace std ;

int main(){

    unsigned int n ;

    while ( cin >> n && n != 0 ) {

        unsigned int fac = ( int ) sqrt( n ) ;

        if (fac * fac == n){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
    }
    return 0 ;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a , b  ;
    while (cin>>a>>b && a != 0 ){
        int cnt=0 ;
        for (int i = a ; i <= b ; i++){
            double x  ;
            int y ;
            x = sqrt(i) ;
            y = sqrt(i) ;
            if (x==y){
                ++cnt ;
            }

        }
        cout<<cnt<<"\n" ;

    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int step = 0 ;
    char s  ;
    bool contained;
    double x1[11] ;
    double y1[11] ;
    double x2[11] ;
    double y2[11] ;
    for (int i = 0 ; i< 11 ; i++){
        cin >> s ;
        if(s=='*'){
            step=i+1;
            break;
        }
        cin>>x1[i]>>y1[i]>>x2[i]>>y2[i] ;
    }
    double a ;
    double b ;
    int point = 0 ;
    while (1){
        cin>>a>>b ;
        if (a==9999.9&& b==9999.9)break ;
        point++ ;
        contained=false;
        for (int i = 0 ; i< step ; i++){

            if (a > x1[i] && a < x2[i] && b < y1[i] && b > y2[i] ){
            cout<<"Point "<<point<<" is contained in figure "<<i+1<<endl;
            contained = true ;
            }


        }
        if (!contained){
            cout<<"Point "<<point<<" is not contained in any figure"<<endl;
            }




    }

    return 0;
}

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int index = 0 , mod , step;
    while(cin>> step >> mod){
        bool vis[mod]={0} ;
        bool bad = false ;
        for (int i = 0; i < mod; ++i){    // I will walk form 0 To Mod-1
            int generated = (index + step)%mod;   // 4+3=7 || 7%5 = 2  (because n%5 = 0 : 5-1 )
            if(vis[generated]==1) {   // if the number repeated ==> break  and this Bad
                bad = true;
                break;
            }
            vis[generated] = 1 ;      // make sure I visited the number
            index = generated;       // to start from where I end
        }
        cout << setw(10) << step << setw(10) << mod << "    ";
        bad ? cout << "Bad Choice\n\n" : cout << "Good Choice\n\n";
    }
}

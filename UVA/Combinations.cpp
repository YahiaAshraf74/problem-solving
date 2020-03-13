/*
#include<bits/stdc++.h>

using namespace std;

long long memo[174][174];

long long C(int a, int b){
    if(b==0 || a==b) return 1;

    if(memo[a][b]!=0) return memo[a][b];

    memo[a][b] = C(a-1,b)+C(a-1,b-1);
    return memo[a][b];
}

int main(){
    int n,k;
    memset(memo,0,sizeof(memo));
    while(cin>>n>>k && n && k)
        cout<<n<<" things taken "<<k<<" at a time is "<<C(n,k)<<" exactly."<<"\n";
    return 0;
}
*/
#include <bits/stdc++.h>

using namespace std;

long double fact (long double n){
    if (n==0) return 1 ;
    return n*fact(n-1);
}
int main (){
    long double m, n;
    while (cin >> m >> n && m && n ){
        long double r = (fact(m))/(fact(m-n)*fact(n));
        cout<<m<<" things taken "<<n<<" at a time is "<<fixed<<setprecision(0)<<r<<" exactly."<<endl;
    }
    unsigned long long h = 13746234145802811498808999936 ;
    cout << h ;
}







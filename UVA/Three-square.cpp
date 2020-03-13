#include <bits/stdc++.h>

using namespace std;

#define SWAP(x,y) { int tmp=x; x=y; y=tmp; }

void print(int j,int a,int b){
	if(j>a)
		SWAP(j,a);
	if(j>b)
		SWAP(j,b);
	if(a>b)
		SWAP(a,b);
	printf("%d %d %d\n",j,a,b);
}

int main(){
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		bool found=false;
		int a,b,j;
		int n;
		scanf("%d",&n);

		for(j=0;j*j<=n;j++){
			int temp=n-j*j;
			a=sqrt((double)temp);
			b=0;
			while(b<=a)
				if(a*a+b*b==temp){
					print(j,a,b);
					found=true;
					break;
				}
				else if(a*a+b*b>temp)
					a--;
				else
					b++;
			if(found)
				break;
		}
		if(!found)
			puts("-1");
	}
	return 0;
}









/* int main()
{
    int i, j, k, n,T;
    int num[50001][3]={0}, record[50001]={1};
    for(i = 0; i*i <= 50000; i++){
        for(j = 0; j*j <= 50000; j++)
            for(k = 0; k*k <= 50000; k++){
                int sum = i*i+j*j+k*k;
                if(sum > 50000)  break;
                if(record[sum] == 0)    num[sum][0] = i, num[sum][1] = j, num[sum][2] = k, record[sum] = 1;
            }
    }
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        if(num[n][0] || num[n][1] || num[n][2])   printf("%d %d %d\n", num[n][0], num[n][1], num[n][2]);
        else        printf("-1\n");
    }
    return 0;
}
*/

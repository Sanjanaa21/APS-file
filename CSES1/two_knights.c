#include<stdio.h>
#include<stdlib.h>
int main(){
    long long int n,i,r1,r2,r;
    scanf("%lld",&n);
    if(n==0)
        printf("0\n");
    for(i=1;i<=n;i++){
        r1=0,r2=0,r=0;
        r1=((i*i)*((i*i)-1))/2;
        r2=4*(i-1)*(i-2);
        r=r1-r2;
        printf("%lld\n",r);
    }
    return 0;
}

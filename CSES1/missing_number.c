#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
int main(){
    long long int n,i,a,s=0,sum=0;
    scanf("%lld",&n);
    s=(n*(n+1))/2;
    for(i=0;i<n-1;i++){
        scanf("%d",&a);
        sum+=a;
    }
    printf("%lld\n",s-sum);

}

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

int main(){
    int n,i;
    printf("Enter n\n");
    scanf("%d",&n);
    int values[n];
    int *dp=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&values[i]);
    }
    dp[0]=values[0];
    dp[1]=max(values[0],values[1]);
    for(i=2;i<n;i++){
        dp[i]=max(dp[i-1],dp[i-2]+values[i]);
    }
    printf("Maximum Value is: %d\n",dp[n-1]);
    free(dp);
}

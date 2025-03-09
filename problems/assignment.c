#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
#define MIN(a,b) ((a)<(b)?(a):(b))

int count_set_bit(int n){
    int c=0,r;
    while(n){
        r=n%2;
        if(r==1){
            c++;
        }
        n=n/2;
    }
    return c;
}

int main(){
    int n,a[1000][1000],i,j,dp[1000],mask,x;
    printf("Enter n\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<(1<<n);i++){
        dp[i]=INT_MAX;
    }
    dp[0]=0;
    for(mask=0;mask<(1<<n);mask++){
        x=count_set_bit(mask);
        for(j=0;j<n;j++){
            if(!(mask&(1<<j))){
                dp[mask|(1<<j)]=MIN(dp[mask|(1<<j)],dp[mask]+a[x][j]);
            }
        }
    }
    int ans=dp[(1<<n)-1];
    printf("Minimum cost function is: %d",ans);

}
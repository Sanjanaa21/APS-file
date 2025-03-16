#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int n,i;
    scanf("%d",&n);
    if(n==2||n==3){
        printf("NO SOLUTION\n");
        return 0;
    }
    for(i=2;i<=n;i=i+2){
        printf("%d ",i);
    }
    for(i=1;i<=n;i=i+2){
        printf("%d ",i);
    }
    return 0;
}

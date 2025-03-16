#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>

int main(){
    long long int n,i,c=0;
    //printf("Enter n\n");
    scanf("%lld",&n);
    int *a=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++){
        if(a[i]<a[i-1]){
            c+=(a[i-1]-a[i]);
            a[i]=a[i-1];
        }
    }
    printf(" %lld",c);
    free(a);
}

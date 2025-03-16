#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int t;
    long long int i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld",&i,&j);
        if(j>=i){
            if(j%2==1){
               printf("%lld\n",j*j-(i-1));
            }
            else{
                printf("%lld\n",(j-1)*(j-1)+i);
            }
        }
        else{
            if(i%2==1){
                printf("%lld\n",(i-1)*(i-1)+j);
            }
            else{
                printf("%lld\n",i*i-(j-1));
            }
        }
    }
    return 0;
}



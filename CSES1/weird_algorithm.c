#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
int main(){
    long long int n;
    scanf("%lld",&n);
    printf("%lld ",n);
    while(n!=1){
        if(n%2==0){
            n=n/2;
        }
        else{
            n=(n*3)+1;
        }
        printf("%lld ",n);
    }
}

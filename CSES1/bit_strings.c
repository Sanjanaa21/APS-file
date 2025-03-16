#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define mod 1000000007

long long int power(long long b,long long e){
    long long r=1;
    while(e>0){
        if(e%2==1){
            r=(r*b)%mod;
        }
        b=(b*b)%mod;
        e/=2;
    }
    return r;
}
int main(){
    long long int n,r;
    scanf("%lld",&n);
    printf("%lld\n",power(2,n));

}

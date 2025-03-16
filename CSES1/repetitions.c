#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<string.h>
int main(){
    char s[1000000];
    scanf("%s",s);
    int i,c=1,max=1;
    for(i=1;s[i]!='\0';i++){
        if(s[i]==s[i-1]){
            c++;
        }else{
            if(c>max){
                max=c;
            }
            c=1;
        }
    }
    if(c>max){
        max=c;
    }
    printf("%d\n",max);
    return 0;
}

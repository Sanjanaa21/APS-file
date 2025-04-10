#include<iostream>
#include<limits.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main(){
    int n,i,j;
    string s1,s2;
    cout<<"enter 2 strings"<<endl;
    cin>>s1>>s2;
    int n1=s1.size();
    int n2=s2.size();
    int dp[n1+1][n2+1];
    for (i=0;i<= n1;i++)
        dp[i][0]=i;
    for (j=0;j<=n2;j++)
        dp[0][j]=j;
    for(i=1;i<=n1;i++){
        for(j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
            }

        }
    }
    cout<<"Length of shortest common subsequence is  "<<dp[n1][n2]<<endl;


}

#include<iostream>
#include<math.h>
using namespace std;
unsigned long int catalan(int n){
    unsigned long int res=0;
    int i;
    if(n<=1){
        return 1;
    }else{
        for(i=0;i<n;i++){
            res+=catalan(i)*catalan(n-i-1);
        }
    }
    return res;
}
int main(){
    int n,i;
    cout<<"Enter n"<<endl;
    cin>>n;
    long long int c;
    for(i=0;i<n;i++){
        c=catalan(i);
        cout<<c<<"  ";
    }
    cout<<endl;
}

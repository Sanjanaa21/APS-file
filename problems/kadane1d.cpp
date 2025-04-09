#include<iostream>
#include<math.h>
#include<limits.h>
using namespace std;

unsigned long int kadanes(int a[],int n, int &st,int &en){
    int mx=INT_MIN,tmax=0;
    int ls=0;
    int i;
    for(i=0;i<n;i++){
        tmax+=a[i];
        if(tmax<0){
            tmax=0;
            ls=i+1;
        }
        if(mx<tmax){
            mx=tmax;
            st=ls;
            en=i;
        }
    }
    return mx;
}
int main(){
    int n,i;
    cout<<"Enter n"<<endl;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    int st=0,en=0;
    unsigned int k=kadanes(a,n,st,en);
    cout<<"Largest subarray sum is  "<<k<<endl;
    cout<<"Start index: "<<st<<", End index:    "<<en<<endl;
}

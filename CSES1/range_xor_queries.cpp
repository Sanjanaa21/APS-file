#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
const int N=1e6+2;
long long int arr[N],tree[4*N];

void build(int node,int st,int en){
    if(st==en){
        tree[node]=arr[st];
    }else{
        int mid=(st+en)/2;
        build(2*node,st,mid);
        build(2*node+1,mid+1,en);
        tree[node]=tree[2*node]^tree[2*node+1];
    }
}
int xors(int node,int st,int en,int a,int b){
    if(a>en||b<st){
        return 0;
    }
    if(st>=a&&en<=b){
        return tree[node];
    }
    int mid=(st+en)/2;
    long long int l=xors(2*node,st,mid,a,b);
    long long int r=xors(2*node+1,mid+1,en,a,b);
    return l^r;
}
int main(){
    int i,n,q,a,b;
    cin>>n>>q;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    build(1,0,n-1);
    while(q--){
        cin>>a>>b;
        a--;
        b--;
        int s=xors(1,0,n-1,a,b);
        cout<<s<<endl;
    }

}

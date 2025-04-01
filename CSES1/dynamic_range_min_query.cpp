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
        return;
    }else{
        long long int mid=(st+en)/2;
        build(2*node,st,mid);
        build(2*node+1,mid+1,en);
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}
void update(int node,int st,int en,int k,int u){
   if(st==en){
        tree[node]=u;
        return;
    }else{
        long long int mid=(st+en)/2;
        if(k<=mid){
            update(2*node,st,mid,k,u);
        }else{
            update(2*node+1,mid+1,en,k,u);
        }
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}
int minimum(int node,int st,int en,int a,int b){
    if(a>en||b<st){
        return INT_MAX;
    }
    if(a<=st&&en<=b){
        return tree[node];
    }
    long long int mid=(st+en)/2;
    long long int l=minimum(2*node,st,mid,a,b);
    long long int r=minimum(2*node+1,mid+1,en,a,b);
    return min(l,r);
}
int main(){
    int i,n,q,a,b,k,u,q1;
    cin>>n>>q;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    build(1,0,n-1);
    while(q--){
        cin>>q1;
        if(q1==1){
            cin>>k>>u;
            k--;
            update(1,0,n-1,k,u);
        }else if(q1==2){
            cin>>a>>b;
            a--;
            b--;
            long long int s=minimum(1,0,n-1,a,b);
            cout<<s<<endl;
        }
    }

}

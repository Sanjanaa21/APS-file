/*#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;
int main(){
    int n,q,i,a,b,mi;
    cin>>n>>q;
    vector<int> arr(n);
    vector<int>ans(n);
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    while(q--){
        cin>>a>>b;
        mi=INT_MAX;
        for(i=a-1;i<b;i++){
            mi=min(mi,arr[i]);
        }
        cout<<mi<<endl;
    }
}
*/

#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1e6+2;
long long int arr[N],tree[4*N];
void build(int node,int st,int en){
    int l,r;
    if(st==en){
        tree[node]=arr[st];
    }else{
        int mid=(st+en)/2;
        build(2*node,st,mid);
        build(2*node+1,mid+1,en);
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}
long long int minimum(int node,int st,int en,int a,int b){
    if(a>en||b<st){
        return INT_MAX;
    }
    if(st>=a&&en<=b){
        return tree[node];
    }
    int mid=(st+en)/2;
    int l=minimum(2*node,st,mid,a,b);  //left child
    int r=minimum(2*node+1,mid+1,en,a,b); //right child
    return min(l,r);

}
int main(){
    int n,q,a,b;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    build(1,0,n-1);
    while(q--){
        cin>>a>>b;
        a--;
        b--;
        long long int m=minimum(1,0,n-1,a,b);
        cout<<m<<endl;
    }
}




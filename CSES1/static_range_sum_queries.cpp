/*#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main(){
    int n,q,i,a,b,s;
    cin>>n>>q;
    vector<int> arr(n);
    vector<long long int> ans(n+1,0);
    for(i=1;i<=n;i++){
        cin>>arr[i-1];
        ans[i]=ans[i-1]+arr[i-1];
    }
    while(q--){
        cin>>a>>b;
        s=sums(arr,a,b);
        cout<<(ans[b]-ans[a-1]<<endl;
    }
}
*/
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
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}
long long int sums(int node,int st,int en,int a,int b){
    if(a>en||b<st){
        return 0;
    }
    if(st>=a&&en<=b){
        return tree[node];
    }
    int mid=(st+en)/2;
    long long int l=sums(2*node,st,mid,a,b);
    long long int r=sums(2*node+1,mid+1,en,a,b);
    return l+r;
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
        long long int s=sums(1,0,n-1,a,b);
        cout<<s<<endl;
    }

}

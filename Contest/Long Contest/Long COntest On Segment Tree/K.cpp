#include<bits/stdc++.h>
using namespace std;
#define sz 100005
int arr[sz];
int tree[4*sz];

void build(int at, int l, int r){
    if(l==r){
        tree[at]=1;
        return ;
    }
    int mid=(l+r)>>1;
    build(at<<1,l,mid);
    build(at<<1|1,mid+1,r);
    tree[at]=tree[at<<1]+tree[at<<1|1];
}

void update(int at, int l, int r, int k){
    if(l==r){
        tree[at]=0;
        return;
    }
    int mid=(l+r)>>1;
    if(k<=tree[at<<1])
        update(at<<1,l,mid,k);
    else
        update(at<<1|1,mid+1,r,k-tree[at<<1]);
    tree[at]=tree[at<<1]+tree[at<<1|1];
}

int query(int at, int l, int r, int  k){

    if(l==r){
        return l;
    }
    int mid=(l+r)>>1;
    if(k<=tree[at<<1])
        return query(at<<1,l,mid,k);
    else
        return query(at<<1|1,mid+1,r,k-tree[at<<1]);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int cs=1,t,n,m,i,j,k;
    cin>>t;
    while(t--){
        cin>>n;
        build(1,1,n);
        for(i=1; i<=n; i++)cin>>arr[i];
        m=n;
        for(i=n; i>1; i--){
            update(1,1,n,m-arr[i]);
            m--;
        }
        cout<<"Case "<<cs++<<": "<<query(1,1,n,1)<<endl;
    }

    return 0;
}

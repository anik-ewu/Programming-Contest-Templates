#include<bits/stdc++.h>
using namespace std;
#define N   100005
#define inf INT_MAX
#define ll long long
ll L,R;
ll arr[N];
ll tree[4*N];
ll lazy[4*N];

void build(ll at, ll l, ll r){
    if(l==r){
        tree[at]=arr[l];
        return;
    }
    ll mid=(l+r)/2;
    build(at*2,l,mid);
    build(at*2+1,mid+1,r);
    tree[at]=tree[at*2]+tree[at*2+1];
}

void update(ll at, ll l, ll r,ll val){
    if(lazy[at]){
        tree[at]+=lazy[at]*((r-l)+1);
        if(l!=r){
            lazy[at*2]+=lazy[at];
            lazy[at*2+1]+=lazy[at];
        }
        lazy[at]=0;
    }
    if(R<l || r<L) return;

    if(L<=l && r<=R){
       tree[at]+=val*((r-l)+1);
       if(l!=r){
        lazy[at*2]+=val;
        lazy[at*2+1]+=val;
       }
       return;
    }
    ll mid=(l+r)/2;
    update(at*2,l,mid,val);
    update(at*2+1,mid+1,r,val);
    tree[at]=tree[at*2]+tree[at*2+1];
}

ll query(ll at, ll l, ll r){

    if(R<l || r<L) return 0;
    if(lazy[at]){
        tree[at]+=lazy[at]*((r-l)+1);
        if(l!=r){
            lazy[at*2]+=lazy[at];
            lazy[at*2+1]+=lazy[at];
        }
        lazy[at]=0;
    }
    if(L<=l && r<=R){
        return tree[at];
    }
    ll mid=(l+r)/2;
    ll q1=query(at*2,l,mid);
    ll q2=query(at*2+1,mid+1,r);
    return (q1+q2);
}

int main(){

    ll t,n,i,cs=1,tp,q,val;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&q);
        memset(arr,0,sizeof(arr));
        memset(lazy,0,sizeof(lazy));
        build(1,1,n);
        printf("Case %lld:\n",cs++);
        while(q--){
            scanf("%lld%lld%lld",&tp,&L,&R);L++,R++;///1 base indexing
            if(tp==1){
                ll sum=query(1,1,n);
                printf("%lld\n",sum);
            }
            else{
                scanf("%lld",&val);
                update(1,1,n,val);
            }
        }
    }
    return 0;
}

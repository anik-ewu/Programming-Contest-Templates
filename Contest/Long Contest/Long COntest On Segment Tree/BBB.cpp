#include<bits/stdc++.h>
using namespace std;
#define N 100005
int R,L;
int lazy[4*N];
struct node{
    int one,two,thr;
}tree[4*N];

struct node combine(node a, node b){
    return {a.one+b.one,a.two+b.two,a.thr+b.thr};
}

void build(int at, int l, int r){
    if(l==r){
        tree[at]={0,0,1};
        return;
    }
    int mid=(l+r)/2;
    build(at*2,l,mid);
    build(at*2+1,mid+1,r);
    tree[at]=combine(tree[at*2],tree[at*2+1]);
}
void move(int at){
    swap(tree[at].one,tree[at].thr);
    swap(tree[at].two,tree[at].thr);
}
void propagate(int at){
    while(lazy[at]){
        move(at);
        lazy[at*2]++;
        lazy[at*2+1]++;
        lazy[at]--;
    }
}
void update(int at, int l, int r){
    lazy[at]=lazy[at]%3;
    ///propagate(at,l,r);
    if(R<l || r<L)return;

    if(L<=l && r<=R){
        move(at);
//        if(l!=r){
//            lazy[at*2]++;
//            lazy[at*2+1]++;
//        }
        return;
    }
    propagate(at);
    int mid=(l+r)/2;
    update(at*2,l,mid);
    update(at*2+1,mid+1,r);
    tree[at]=combine(tree[at*2],tree[at*2+1]);
}

int query(int at, int l, int r){
    lazy[at]=lazy[at]%3;
    propagate(at);
    if(R<l || r<L)return 0;
    if(L<=l && r<=R){
        return tree[at].thr;
    }
    ///propagate(at);
    int mid=(l+r)/2;
    return (query(at*2,l,mid)+query(at*2+1,mid+1,r));///sum
}

int main(){

    int n,i,q,t,cs=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        build(1,1,n);
        printf("Case %d:\n",cs++);
        int tp;
        memset(lazy,0,sizeof(lazy));
        while(q--){
            scanf("%d%d%d",&tp,&L,&R);L++;R++;
            if(tp)
                printf("%d\n",query(1,1,n));
            else
                update(1,1,n);
        }
    }
    return 0;
}

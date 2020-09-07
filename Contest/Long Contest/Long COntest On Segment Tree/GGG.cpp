#include<bits/stdc++.h>
using namespace std;
#define N 100005
int L,R;
int arr[N];
struct node{
    int val;
    int idx;
}tree[4*N];

void build(int at, int l, int r){

    if(l==r){
        tree[at].val=arr[l];
        tree[at].idx=l;
        return;
    }
    int mid=(l+r)/2;
    build(at*2,l,mid);
    build(at*2+1,mid+1,r);
    if(tree[at*2].val>tree[at*2+1].val)
        tree[at]=tree[at*2];
    else
        tree[at]=tree[at*2+1];
}

void update(int at, int l, int r,int id, int vl){

    if(id<l || id>r)return;

    if(l==r){
        arr[id]=vl;
        tree[at].val=arr[l];
        tree[at].idx=id;
        return;
    }
    int mid=(l+r)/2;
    if(id<=mid)
        update(at*2,l,mid,id,vl);
    else
        update(at*2+1,mid+1,r,id,vl);
    if(tree[at*2].val>tree[at*2+1].val)
        tree[at]=tree[at*2];
    else
        tree[at]=tree[at*2+1];
}

struct node query(int at, int l, int r){

    if(R<l || r<L)return{-1,0};
    if(L<=l && r<=R){
        return tree[at];
    }
    int mid=(l+r)/2;
    struct node q1=query(at*2,l,mid);
    struct node q2=query(at*2+1,mid+1,r);
    if(q1.val>q2.val)
        return q1;
    else
        return q2;
};

int main(){

    int n,i,q;
    scanf("%d",&n);
    for(i=1; i<=n; i++){
        scanf("%d",&arr[i]);
    }
    build(1,1,n);
    scanf("%d",&q);
    char tp;
    int sum;
    int id,vl,S_R;
    struct node s1,s2,s3;
    while(q--){
        tp=getchar();///ignoring digit or Enter
        tp=getchar();
        if(tp=='Q'){
          scanf("%d%d",&L,&R);
          S_R=R;
          s1=query(1,1,n);
          sum=s1.val;
          R=s1.idx-1;
          s2=query(1,1,n);
          R=S_R;
          L=s1.idx+1;
          s3=query(1,1,n);
          sum+=max(s2.val,s3.val);
          printf("%d\n",sum);
        }
        else{
            scanf("%d%d",&id,&vl);
            update(1,1,n,id,vl);
        }
    }
    return 0;
}

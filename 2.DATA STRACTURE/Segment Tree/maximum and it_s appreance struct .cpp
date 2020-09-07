#include<bits/stdc++.h>
using namespace std;
#define sz 100005
int arr[sz],L,R;

struct pii{
    int a;
    int b;
};

struct pii tree[sz*4];

struct pii combine(struct pii aa,struct pii bb){
    if(aa.a>bb.a) return aa;
    if(aa.a<bb.a) return bb;
    return {aa.a,aa.b+bb.b};
}

void build(int node, int l, int r){

    if(l==r){
        tree[node]={arr[l],1};
        return ;
    }

    int mid=(l+r)/2;

    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    tree[node]=combine(tree[node*2],tree[node*2+1]);
}

struct pii get_max(int node, int l, int r){

    if(R<l || L>r)
    return {-1,0};
    if(L<=l and r<=R){
        return tree[node];
    }
    int mid=(l+r)/2;
    return combine(get_max(node*2,l,mid),get_max(node*2+1,mid+1,r));
}

void update(int node, int l, int r, int pos, int val){

    if(l>r)return;
    if(l==r){
        tree[node]={val,1};
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)
        update(node*2,l,mid,pos,val);
    else
        update(node*2+1,mid+1,r,pos,val);
    tree[node]=combine(tree[node*2],tree[node*2+1]);
}

int main(){

    int n,i,j,l,r,q,key,val,pos;
     cin>>n;
     for(i=1; i<=n; i++)cin>>arr[i];
     build(1,1,n);

     while(cin>>key){
        struct pii ans;
        if(key==1){
        cin>>L>>R;
        ans=get_max(1,1,n);
        cout<<ans.a<<' '<<ans.b<<endl;}
        else{
            cin>>pos>>val;
            update(1,1,n,pos,val);
        }
     }

  return 0;
}

/*
INPUT :
10
1 2 2 3 3 3 4 4 4 4
1 1 10
2 6 4
1 1 10

OUTPUT:
4 4
4 5
*/



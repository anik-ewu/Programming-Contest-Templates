#include<bits/stdc++.h>
using namespace std;
#define sz 600100
int L,R;
int tree[sz];
int lazy[sz];
map< int , int > mp;
vector < int > cmp,qr;

struct st{
    int l,r;
}arr[sz];

void init(){
    mp.clear();
    cmp.clear();
    qr.clear();
    memset(lazy,0,sizeof(lazy));
}

void process(){
    mp.clear();
    sort(cmp.begin(),cmp.end());
    for(int i=0; i<cmp.size(); i++){
      mp[cmp[i]]=i+1;
    }
}
void build(int node, int l, int r){
    if(l==r){
        tree[node]=0;
        return;
    }
    int mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    tree[node]=tree[node*2]+tree[node*2+1];
}
void update(int at, int l, int r,int val){
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
    int mid=(l+r)/2;
    update(at*2,l,mid,val);
    update(at*2+1,mid+1,r,val);
    tree[at]=tree[at*2]+tree[at*2+1];
}

int query(int at, int l, int r){

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
    int mid=(l+r)/2;
    int q1=query(at*2,l,mid);
    int q2=query(at*2+1,mid+1,r);
    return (q1+q2);
}



int main(){

    int l,r,n,q,i,cs=1,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        init();
        for(i=1; i<=n; i++){
            scanf("%d%d",&l,&r);
            arr[i].l=l;arr[i].r=r;
            if(mp[l]==0)
              cmp.push_back(l),mp[l]=1;
            if(mp[r]==0)
              cmp.push_back(r),mp[r]=1;
        }
        int point;
        for(i=1; i<=q; i++){
             scanf("%d",&point);
             qr.push_back(point);
             if(mp[point]==0)
              cmp.push_back(point);
            mp[point]=1;
        }
        process();
        int N=mp[cmp[cmp.size()-1]];
        build(1,1,N);
        for(i=1; i<=n; i++){
            L=mp[arr[i].l];
            R=mp[arr[i].r];
            update(1,1,N,1);
        }
        printf("Case %d:\n",cs++);
        for(i=0; i<q; i++){
            L=mp[qr[i]];
            R=mp[qr[i]];
            if(L<=N)
                printf("%d\n",query(1,1,N));
            else
                printf("%d\n",0);
        }
    }
    return 0;
}

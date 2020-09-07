#include<bits/stdc++.h>
using namespace std;
#define sz 1024010
string s,p;
int L,R;
int tree[4*sz];
int lazy[4*sz];

int doflip(int x){
    if(x==1)return 2;
    if(x==2)return 1;
    if(x==3)return 0;
    if(x==0)return 3;
}

void build(int at, int l, int r){

    if(l==r){
        tree[at]=s[l-1]-'0';
        return;
    }
    int mid=(l+r)/2;
    build(at*2,l,mid);
    build(at*2+1,mid+1,r);
    tree[at]=(tree[at*2]+tree[at*2+1]);
}
void propagate(int at, int l, int r){

    if(lazy[at]==0)return;
    if(lazy[at]==1) tree[at]=((r-l)+1);
    if(lazy[at]==2) tree[at]=0;
    if(lazy[at]==3) tree[at]=(r-l+1)-tree[at];

    if(l!=r){
        if(lazy[at]==1 || lazy[at]==2){
            lazy[at*2]=lazy[at];
            lazy[at*2+1]=lazy[at];
        }
        else{
            lazy[at*2]=doflip(lazy[at*2]);
            lazy[at*2+1]=doflip(lazy[at*2+1]);
        }
    }
    lazy[at]=0;
}

void update(int at, int l, int r, int val){

    propagate(at,l,r);
    if(R<l || r<L) return;
    if(L<=l && r<=R){
        if(val==3){
            tree[at]=(r-l+1)-tree[at];
            if(l!=r){
            lazy[at*2]=doflip(lazy[at*2]);
            lazy[at*2+1]=doflip(lazy[at*2+1]);
            }
            return;
        }
        if(val==1) tree[at]=(r-l+1);
        if(val==2) tree[at]=0;
        if(l!=r){
        lazy[at*2]=val;
        lazy[at*2+1]=val;
       }
       return;
    }
    int mid=(l+r)/2;
    update(at*2,l,mid,val);
    update(at*2+1,mid+1,r,val);
    tree[at]=tree[at*2]+tree[at*2+1];
}
int query(int at, int l, int r){

    propagate(at,l,r);
    if(R<l || r<L) return 0;
    if(L<=l && r<=R){
        return tree[at];
    }
    int mid=(l+r)/2;
    int q1=query(at*2,l,mid);
    int q2=query(at*2+1,mid+1,r);
    return (q1+q2);
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ///freopen("Out.txt","w",stdout);
    int t,n,m,q,T,cs=1;
    cin>>t;
    while(t--){
        cin>>m;
        s="";
        while(m--){
           cin>>T>>p;
           while(T--){
            s+=p;
           }
        }
        n=s.size();
        build(1,1,n);
        cout<<"Case "<<cs++<<":"<<'\n';
        cin>>q;
        int cas=1;
        char tp;
        memset(lazy,0,sizeof(lazy));
        while(q--){
            cin>>tp>>L>>R;L++;R++;

            if(tp=='F'){
                update(1,1,n,1);
            }
            else if(tp=='E'){
                update(1,1,n,2);
            }
            else if(tp=='I'){
                update(1,1,n,3);
            }
            else{
                cout<<"Q"<<cas++<<": "<<query(1,1,n)<<'\n';
            }
        }
    }

    return 0;
}

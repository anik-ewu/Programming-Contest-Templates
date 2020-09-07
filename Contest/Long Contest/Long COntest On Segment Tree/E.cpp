#include<bits/stdc++.h>
using namespace std;
#define sz 200005
int L,R,N;
int arr[sz];
int tree[4*sz];

void build(int at, int l, int r){

    if(l==r){
        if(l<=N) tree[at]=1;
        else tree[at]=0;
        return ;
    }
    int mid=(l+r)/2;
    build(at*2,l,mid);
    build(at*2+1,mid+1,r);
    tree[at]=tree[at*2]+tree[at*2+1];
}
int call(int at, int l, int r, int k){


    if(l==r){
        return arr[l];
    }
    int mid=(l+r)/2;
    if(k<=tree[at*2]){
        return call(at*2,l,mid,k);
    }
    else
        return call(at*2+1,mid+1,r,k-tree[at*2]);
}

void del(int at, int l, int r, int k){

    if(l==r){
        tree[at]=0;
        return;
    }

    int mid=(l+r)/2;
    if(k<=tree[at*2])
        del(at*2,l,mid,k);
    else
        del(at*2+1,mid+1,r,k-tree[at*2]);
    tree[at]=tree[at*2]+tree[at*2+1];
}

void add(int at, int l, int r, int pos, int id){

    if(pos<l || pos > r)return;
    if(l==r){
        arr[l]=id;
        tree[at]=1;
        return;
    }
    int mid=(l+r)/2;
    add(at*2,l,mid,pos,id);
    add(at*2+1,mid+1,r,pos,id);
    tree[at]=tree[at*2]+tree[at*2+1];
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char f;
    int cs=1,t,n,m,i,j;

    cin>>t;
    while(t--){
        cin>>n>>m;
        N=n;
        for(i=1; i<=n; i++)
            cin>>arr[i];
        build(1,1,2*n);
        int id;
        int added=0;
        cout<<"Case "<<cs++<<":"<<endl;
        while(m--){
            cin>>f>>id;
            if(f=='c'){
                int val=call(1,1,2*n,id);
                if(val){
                    del(1,1,2*n,id);
                cout<<val<<endl;
                }
                else{
                    cout<<"none"<<endl;
                }

            }
            else{
                added++;
                add(1,1,2*n,n+added,id);
            }
        }
    }


    return 0;
}

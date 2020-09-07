#include<bits/stdc++.h>
#define N 1000005
using namespace std;
int L,R;
string s;
struct node{
    int total, op,cl;
}tree[4*N];

node combine(node a, node b){
    int total=a.total+b.total;
    int mn=min(a.op,b.cl);
    total+=mn;
    return {total,a.op+b.op-mn,a.cl+b.cl-mn};
}

void build(int at, int l, int r){
    if(l==r){
        tree[at]={0,s[l-1]=='('?1:0,s[l-1]==')'?1:0};
        return;
    }
    int mid=(l+r)/2;
    build(at*2,l,mid);
    build(at*2+1,mid+1,r);
    tree[at]=combine(tree[at*2],tree[at*2+1]);
}

node query(int at, int l, int r){

    if(R<l || r<L) return {-1,0,0};
    if(L<=l && r<=R){
        return tree[at];
    }
    int mid=(l+r)/2;
    node left=query(at*2,l,mid);
    node right=query(at*2+1,mid+1,r);
    if(left.total==-1)
        return right;
    if(right.total==-1)
        return left;
    return combine(left,right);
}

int main(){

    cin>>s;
    build(1,1,s.size());
    int q;
    cin>>q;
    while(q--){
        cin>>L>>R;
        cout<<(query(1,1,s.size()).total)*2<<endl;
    }


}

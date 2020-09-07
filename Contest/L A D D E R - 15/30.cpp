///Date     : 5.5.2020
///Tags     : Graph + Segment tree
///Idea     : Find the LIS
///Comments : Just because someone stumbles, loses their way, doesn't mean they lost forever.
#include<bits/stdc++.h>
using namespace std;
#define sz 100005
int arr[sz];
int tree[sz*4];

int query(int at, int l, int r, int L, int R){
    if(R<l || r<L)return 0;
    if(L<=l && r<=R)return tree[at];
    int mid=(l+r)/2;
    return max(query(at*2,l,mid,L,R),query(at*2+1,mid+1,r,L,R));
}
void update(int at, int l, int r, int pos, int val){

    if(pos<l || pos>r)return;
    if(l==r){
        tree[at]=val;
        return;
    }
    int mid=(l+r)/2;
    update(at*2,l,mid, pos,val);
    update(at*2+1,mid+1, r, pos,val);
    tree[at]=max(tree[at*2],tree[at*2+1]);
}

int main(){

    int n,i,v,mx=0;
    cin>>n;
    for(i=1; i<=n; i++){
        cin>>arr[i];
        v=query(1,1,n,1,arr[i]-1);
        update(1,1,n,arr[i],v+1);
        mx=max(mx,v+1);
    }
    cout<<mx<<endl;

    return 0;
}
/*
Input:
7
1 4 3 2 5 6 7
Output:
5
*/


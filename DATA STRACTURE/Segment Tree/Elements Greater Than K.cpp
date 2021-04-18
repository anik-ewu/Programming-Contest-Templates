///11 April 2021
///Algorithm: Segment Tree + Binary Search
///Elements greater than K in a range


#include<bits/stdc++.h>
using namespace std;
#define sz 30000

int L,R;
int arr[sz];
vector < int > v[4*sz];

void build(int at, int l, int r){

    if(l==r){
        v[at].push_back(arr[l]);
        return;
    }
    int mid=(l+r)/2;
    build(at*2,l,mid);
    build(at*2+1,mid+1,r);
    merge(v[at*2].begin(),v[at*2].end(),v[at*2+1].begin(),v[at*2+1].end(),back_inserter(v[at]));
}

int query(int at, int l, int r, int k){

    if(R<l || r<L )return 0;
    if(L<=l && r<=R){
        return v[at].size()-(upper_bound(v[at].begin(),v[at].end(),k)-v[at].begin());
    }
    int mid=(l+r)/2;
    return (query(at*2,l,mid,k)+query(at*2+1,mid+1,r,k));
}

int main(){

    int i,n,q,k;
    scanf("%d",&n);
    for(i=1; i<=n; i++){
        scanf("%d",&arr[i]);
    }
    build(1,1,n);
    scanf("%d",&q);
    while(q--){
        scanf("%d%d%d",&L,&R,&k);
        printf("%d\n",query(1,1,n,k));
    }

   return 0;
}

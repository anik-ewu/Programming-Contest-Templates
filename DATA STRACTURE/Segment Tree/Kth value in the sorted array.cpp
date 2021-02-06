#include<bits/stdc++.h>
using namespace std;
#define sz 100001

int L,R;
int arr[sz];
vector < int > v[4*sz];
struct st{
    int x,y;
}in[sz];

bool cmp(st a, st b){
    return a.x<b.x;
}

void build(int at, int l, int r){

    if(l==r){
        v[at].push_back(in[l].y);
        return ;
    }
    int mid=(l+r)/2;
    build(at*2,l,mid);
    build(at*2+1,mid+1,r);
    merge(v[at*2].begin(),v[at*2].end(),v[at*2+1].begin(),v[at*2+1].end(),back_inserter(v[at]));
}

int query(int at, int l, int r,int k){
    if(l==r){
        return v[at][0];
    }
    int p=upper_bound(v[at*2].begin(),v[at*2].end(),R)-lower_bound(v[at*2].begin(),v[at*2].end(),L);
    int mid=(l+r)/2;
    if(p>=k)
        return query(at*2,l,mid,k);
    else return query(at*2+1,mid+1,r,k-p);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,t,q,i,k;
    cin>>n>>q;
    for(i=1; i<=n; i++){
        cin>>arr[i];
        in[i]={arr[i],i};
    }
    sort(in+1,in+n+1,cmp);

    build(1,1,n);
    while(q--){
        cin>>L>>R>>k;
        cout<<arr[query(1,1,n,k)]<<endl;
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define sz  100005
#define mod 1000000007
int N;
int arr[sz];
int tree[4*sz];
vector < int > cmp;
map < int , int > mp;

void build(int at, int l, int r){
    if(l==r){
        tree[at]=0;
        return ;
    }
    int mid=(l+r)>>1;
    build(at<<1,l,mid);
    build(at<<1|1,mid+1,r);
    tree[at]=tree[at<<1]+tree[at<<1|1];
}

void compress(){
    sort(cmp.begin(),cmp.end());
    mp.clear();
    for(int i=0; i<cmp.size(); i++){
      mp[cmp[i]]=i+1;
    }
}

int query(int at, int l, int r, int L, int R){

    if(R<l || r<L)return 0;
    if(L<=l and r<=R){
        return tree[at];
    }
    int mid=(l+r)>>1;
    return((query(at<<1,l,mid,L,R)%mod)+(query(at<<1|1,mid+1,r,L,R)%mod))%mod;
}

void update(int at, int l, int r, int idx){

    if(idx<l || idx>r)return;
    if(l==r){;
        tree[at]+=(1+query(1,1,N,idx+1,N))%mod;
        tree[at]=tree[at]%mod;
        return;
    }
    int mid=(l+r)>>1;
    if(idx<=mid)
        update(at<<1,l,mid,idx);
    else
        update(at<<1|1,mid+1,r,idx);
    tree[at]=tree[at<<1]+tree[at<<1|1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int cs=1,t,n,m,i,j,k,l,po;
    cin>>t;
    while(t--){
        cin>>m;
        mp.clear();
        cmp.clear();
        for(i=1; i<=m; i++){
            cin>>arr[i];
            if(mp[arr[i]]==0)
                cmp.push_back(arr[i]);
            mp[arr[i]]=1;
        }
        compress();
        N=n=cmp.size();
        build(1,1,n);
        for(i=m; i>=1; i--){
            int idx=mp[arr[i]];
            update(1,1,n,idx);
        }
        long long int ans=query(1,1,n,1,n)%mod;
        cout<<"Case "<<cs++<<": "<<ans<<endl;
    }
    return 0;
}
//int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//
//    int cs=1,t,n,m,i,j,k,l,ll;
//    cin>>t;
//    while(t--){
//        cin>>m;
//        mp.clear();
//        cmp.clear();
//        for(i=1; i<=m; i++){
//            cin>>arr[i];
//            if(mp[arr[i]]==0)
//                cmp.push_back(arr[i]);
//            mp[arr[i]]=1;
//        }
//        compress();
//        N=n=cmp.size();
//        build(1,1,n);
//        for(i=m; i>=1; i--){
//            int idx=mp[arr[i]];
//            update(1,1,n,idx);
//        }
//        long long int ans=query(1,1,n,1,n)%mod;
//        cout<<"Case "<<cs++<<": "<<ans<<endl;
//    }
//
//    return 0;
//}

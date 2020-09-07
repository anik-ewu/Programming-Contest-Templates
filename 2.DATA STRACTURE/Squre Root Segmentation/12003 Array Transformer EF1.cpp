///UVA       : 12003 Array Transformer
///Approach  : Square Root Decomposition
///Complexity: 2.330s(5s)

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int len;
vector<ll int> block[1832];
vector<ll int> arr(300000);
int query(int l, int r, int v){

    int cnt=0;
    int cl=l/len;
    int cr=r/len;
    if(cl==cr){
        for(int i=l; i<=r; i++){
            if(arr[i]<v)cnt++;
        }
    }
    else{
        for(int i=l, end=(cl+1)*len-1;i<=end; ++i){
            if(arr[i]<v)cnt++;
        }
        for(int i=cl+1; i<=cr-1; i++){
            int idx=lower_bound(block[i].begin(),block[i].end(),v)-block[i].begin();
            cnt+=idx;
        }
        for(int i=cr*len; i<=r; i++){
            if(arr[i]<v)cnt++;
        }
    }
    return cnt;
}

int main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    ll int n,i,m,u,l,r,v,p,k;
    cin>>n>>m>>u;
    len=sqrt(n)+1;
    for(i=0; i<n; i++){
        cin>>arr[i];
        block[i/len].push_back(arr[i]);
    }
    ///preprocessing
    for(i=0; i<len; i++){
        if(block[i].size()){
            sort(block[i].begin(),block[i].end());
        }
    }
    while(m--){
        cin>>l>>r>>v>>p;
        l--,r--,p--;
        k=query(l,r,v);///minimum
        arr[p]=(u*k)/(r-l+1);

        l=(p/len)*len;
        r=l+len;
        block[p/len].clear();///clear
        for(i=l; i<n && i<l+len; i++){
            block[i/len].push_back(arr[i]);///copy new block
        }
        sort(block[p/len].begin(),block[p/len].end());///swap for optimization
    }
    for(i=0; i<n; i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}

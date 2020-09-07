///SPOJ      :GIVEAWAY
///Approach  :Square Root Decomposition
///Complexity:4.43s
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int len;
vector<ll int> block[800];
vector<ll int> arr(500005);
int query(int l, int r, int v){

    int cnt=0;
    int cl=l/len;
    int cr=r/len;
    if(cl==cr){
        for(int i=l; i<=r; i++){
            if(arr[i]>=v)cnt++;
        }
    }
    else{
        for(int i=l, end=(cl+1)*len-1;i<=end; ++i){
            if(arr[i]>=v)cnt++;
        }
        for(int i=cl+1; i<=cr-1; i++){
            int idx=lower_bound(block[i].begin(),block[i].end(),v)-block[i].begin();
            cnt+=(len-idx);
        }
        for(int i=cr*len; i<=r; i++){
            if(arr[i]>=v)cnt++;
        }
    }
    return cnt;
}

int main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    ll int n,i,q,l,r,idx,type,val,k;
    cin>>n;
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
    cin>>q;
    while(q--){
        cin>>type;
        if(type==0){
            cin>>l>>r>>val;
            l--;
            r--;
            k=query(l,r,val);
            cout<<k<<endl;
        }
        else{
            cin>>idx>>val;
            idx--;
            arr[idx]=val;
            l=(idx/len)*len;
            r=l+len;
            block[idx/len].clear();///clear
            for(i=l; i<n && i<l+len; i++){
                block[i/len].push_back(arr[i]);///copy new block
            }
            sort(block[idx/len].begin(),block[idx/len].end());///swap for optimization
        }
    }
    return 0;
}


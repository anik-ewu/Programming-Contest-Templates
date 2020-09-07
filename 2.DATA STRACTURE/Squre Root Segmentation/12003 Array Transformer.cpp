///UVA       : 12003 Array Transformer
///Approach  : Square Root Decomposition
///Complexity: 3.330s(5s)

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int len;
vector<ll int> block[1832];
vector<ll int> arr(300000);
vector<pair<ll int , ll int > > mark[1832];

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
        mark[i/len].push_back({arr[i],i});
    }
    ///preprocessing
    for(i=0; i<len; i++){
        if(block[i].size()){
            sort(block[i].begin(),block[i].end());
            sort(mark[i].begin(),mark[i].end());
        }
    }
    while(m--){
        cin>>l>>r>>v>>p;
        l--,r--,p--;
        k=query(l,r,v);
        ll int val=(u*k)/(r-l+1);
        arr[p]=val;
        block[p/len].clear();
        mark[p/len].clear();
        l=(p/len)*len;
        r=l+len;
        for(i=l; i<n && i<l+len; i++){
            block[i/len].push_back(arr[i]);
            mark[i/len].push_back({arr[i],i});
        }

        sort(block[p/len].begin(),block[p/len].end());
        ///sort(mark[p/len].begin(),mark[p/len].end());
        ///swapping instead of sorting
//        i=p%len;;
//        int blk=p/len;
//        while(i<block[blk].size()-1 && block[blk][i]>block[blk][i+1]){
//            swap(block[blk][i],block[blk][i+1]);
//        }
//        l=(p/len)*len;
//        while(i>l && block[blk][i]<block[blk][i-1]){
//            swap(block[blk][i],block[blk][i-1]);
//        }
    }
    vector< pair < int , int > >marr;
    for(i=0; i<len; i++){
        for(int j=0; j<mark[i].size(); j++){
            marr.push_back({mark[i][j].second,mark[i][j].first});
        }
    }
    sort(marr.begin(),marr.end());
    for(i=0; i<n; i++){
        cout<<marr[i].second<<endl;
    }
    return 0;
}

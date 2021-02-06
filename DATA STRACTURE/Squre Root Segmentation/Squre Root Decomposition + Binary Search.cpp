///Square Root Decomposition
///Date      :  6-09-2020
///Complexity:  N*sqrt(N)
///Challenge :  Find the occurrence of number in L to R which is < K


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define N       300000
#define sqrtN   550

int len;
vector<ll > arr(N);
vector<ll > block[sqrtN];

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
        for(int i=l, i<(cl+1)*len; i++){
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

    ll  n, q, l, r;
    cin>>n>>q;

    len=sqrt(n)+1;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        block[i/len].push_back(arr[i]);
    }
    ///sorting block for binary search
    for(int i=0; i<len; i++){
        if(block[i].size()){
            sort(block[i].begin(),block[i].end());
        }
    }

    ll tot, k;
    while(q--){
        cin>>l>>r>>k;
        l--,r--;/// 0 based indexing
        tot=query(l,r,k);
        cout<<tot<<endl;
    }
    return 0;
}

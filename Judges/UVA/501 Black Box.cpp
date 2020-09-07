/// Program showing a policy-based data structure.

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class key,class value= null_type,class cmp= less<key>>
using pbds_set = tree<key,value,cmp,rb_tree_tag,tree_order_statistics_node_update>;

#define sz 300005
typedef long long ll;
ll arr[sz], brr[sz];

int main(){


    ll k,n,m,cs=0;
    cin>>k;
    while(k--){
        cin>>n>>m;
        for(int i=1; i<=n; i++)cin>>arr[i];
        for(int i=1; i<=m; i++)cin>>brr[i];

        if(cs)
            cout<<endl;
        cs=1;

        ll j=1;
        ll c=0;
        ll index=0;
        pair < ll , ll > pii;
        pbds_set< pair < ll , ll > > st;
        for(int i=1; i<=n; i++){
            st.insert({arr[i],c++});
            if(i==brr[j]){
               while(i==brr[j] && j<=m){
                    auto ret=st.find_by_order(index);
                    pii=*ret;
                    cout<<pii.first<<endl;
                    j++;
                    index++;
               }
            }
        }
    }
    return 0;
}


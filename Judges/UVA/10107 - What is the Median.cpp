#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
template<class key,class value= null_type,class cmp= less<key>>
using pbds_set = tree<key,value,cmp,rb_tree_tag,tree_order_statistics_node_update>;

#define Fast     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int main(){

    Fast;

    int len;
    int median, a,c=0;
    pair <int , int > pii;
    pbds_set< pair < int , int > > st;
    while(cin>>a){
        st.insert({a,c++});
        len=st.size()/2;
        auto res=st.find_by_order(len);
        pii=*res;
        median=pii.first;
        if(st.size()%2==0){
            auto res=st.find_by_order(len-1);
            pii=*res;
            median+=pii.first;
            median/=2;
        }
        cout<<median<<endl;
    }
    return 0;
}

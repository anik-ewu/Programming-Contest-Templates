#include<bits/stdc++.h>
using namespace std;

int arr[100005];
bool check(int mid, int k ,int n){
    int need;
    for(int i=1; i<=n; i++){
        need=arr[i]/mid;
        if(arr[i]%mid)need++;
        if(k<need)return false;
        k-=need;
    }
    return true;
}
int Bsearch(int k, int n){

    int lo=1;
    int hi=1010;///though max ans can be up to 1000
    int mn=3;

    while(hi-lo>2){
        int mid=(lo+hi)/2;

        if(check(mid, k, n)){
            mn=mid;
            hi=mid;
        }
        else{
            lo=mid+1;
        }
    }
    while(mn-1 && check(mn-1,k,n))mn--;
    return mn;
}

int main(){

    int t,n,i,k;
    while(cin>>k>>n){
        for(i=1; i<=n; i++){
            cin>>arr[i];
        }
        int ans=Bsearch(k,n);
        cout<<ans<<endl;
    }
    return 0;
}


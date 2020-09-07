///Date     : 23.5.2020
///Tags     : Two Pointer + Sorting + Prefix Sum
///Idea     : Sort the array, build prefix sum, then for each i 1 to N calculate the freq of arr[i] after using k.
///           Main observation is, if i<j and arr[i] is not increasing the frequency of arr[j] then it will not increase
///           the frequency of the rest j+1 to N. so we can discard i for further calculation.

///Comments : Just because someone stumbles, loses their way, doesn't mean they lost forever.

#include<bits/stdc++.h>
using namespace std;
#define sz 100005
#define ll long long
ll arr[sz],brr[sz];

int main(){

    ll k,n,i,j;
    cin>>n>>k;
    for(i=1; i<=n; i++){
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1);
    for(i=1; i<=n; i++){
        brr[i]=arr[i]+brr[i-1];
    }

    j=1;
    ll need, have, value, freq=-1;
    for(i=1; i<=n; i++){
        while(true){
            need=arr[i]*(i-j+1);
            have=brr[i]-brr[j-1]+k;
            if(have>=need)break;
            j++;
        }
        int curr=(i-j+1);
        if(curr>freq){
            freq=curr;
            value=arr[i];
        }
    }
    cout<<freq<<' '<<value<<endl;

    return 0;
}

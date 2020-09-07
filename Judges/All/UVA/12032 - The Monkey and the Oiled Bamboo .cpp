#include<bits/stdc++.h>
using namespace std;

int arr[100005];

bool check(int n, int k){

    if(arr[1]>k)return false;
    if(arr[1]==k)k--;
    for(int i=2; i<=n; i++){
        if(arr[i]-arr[i-1]>k)
            return false;
        if(arr[i]-arr[i-1]==k)
            k--;
        if(k<1 and i<n)return false;
      }
    return true;
}


int bsearch(int n){

    int ans,cnt=0,high,low,mid;
    low=1;
    high=10000005;
    while(cnt++<100 and low<high){

        mid=(low+high)/2;

        if(check(n,mid)){
            ans=mid;
            high=mid;
        }
        else
            low=mid+1;
    }
  return ans;
}

int main(){

    int t,n,i,j;

    scanf("%d",&t);{

    for(i=1; i<=t; i++){

        scanf("%d",&n);
        for(j=1; j<=n; j++){
            scanf("%d",&arr[j]);
         }

        int ans =bsearch(n);
        printf("Case %d: %d\n",i,ans);
       }
    }
    return 0;
}

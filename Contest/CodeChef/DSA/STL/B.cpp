#include<bits/stdc++.h>
using namespace std;

#define sz 200005

int arr[sz],brr[sz];

void solve(int n, int m){

    int val;
    int pmx,pmn;

    val=-INT_MAX;
    for(int i=1; i<=n; i++){
        if(arr[i]>val){
            val=arr[i];
            pmx=i;
        }
    }

    val=INT_MAX;
    for(int i=1; i<=m; i++){
        if(brr[i]<val){
            val=brr[i];
            pmn=i;
        }
    }

    for(int i=1; i<=n; i++){
        cout<<i-1<<' '<<pmn-1<<endl;
    }
    for(int i=1;i<=m;i++){
        if(i==pmn)continue;
        cout<<pmx-1<<' '<<i-1<<endl;
    }
}

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<=m;i++)cin>>brr[i];

    solve(n,m);

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e9;

#define mod             1000000007
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
#define read(x)         freopen("in.txt","r",stdin);
#define write(x)        freopen("out.txt","w",stdout);
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define sz              105

int arr[sz];

string solve(int n){

    ll sum=0;
    int mx=0;

    for(int i=1; i<=n; i++){
        mx=max(mx,arr[i]);
        sum=sum+arr[i];
    }
    if(mx>sum-mx || sum%2){
        return "T";
    }
    else{
        return "HL";
    }
}

int main(){
    Fast;///using Fast I/O
    int a,b,c, i,j,k, t,n,m;

    cin>>t;
    while(t--){
        cin>>n;
        for(i=1; i<=n; i++){
            cin>>arr[i];
        }
        cout<<solve(n)<<endl;
    }
    return 0;
}


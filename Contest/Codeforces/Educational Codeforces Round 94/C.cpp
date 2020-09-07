#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e9;

#define mod             1000000007
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
#define read(x)         freopen("in.txt","r",stdin);
#define write(x)        freopen("out.txt","w",stdout);
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define sz              3000005

string s;
int arr[sz];

void solve(int x){

    memset(arr,-1,sizeof(arr));
    int n=s.size();

    for(int i=1; i<=x && i<=n; i++){
       arr[i+x]=s[i-1]-'0';
    }
    for(int i=n; i>=1 && n-i<x; i--){
        arr[n-x]=s[i-1]-'0';
    }

    for(int i=1; i<=n; i++){
        cout<<arr[i];
    }
    cout<<endl;

}

int main(){
    Fast;///using Fast I/O
    int t,x;

    cin>>t;
    while(t--){
        cin>>s;
        cin>>x;
        solve(x);
    }
    return 0;
}


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
    for(int i=n; i>=1 && n-i<=x; i--){
        arr[n-x+1]=s[i-1]-'0';
    }

    for(int i=x+1; i<=n-x; i++){
        if(s[i-1]-'0'==0){
            arr[i-x]=arr[i+x]=0;
        }
        else{
            if(arr[i-x]==-1){
                arr[i-x]=1;
            }
            else{
                arr[i+x]=1;
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(arr[i]==-1)arr[i]=1;
    }

    bool ok=true;
    for(int i=1; i<=n; i++){
        if(s[i-1]=='0' && i-x>=1 && arr[i-x]==1)ok=false;
        if(s[i-1]=='0' && i+x<=n && arr[i+x]==1)ok=false;
        if(s[i-1]=='1'){
            bool oo=false;
            if(i-x>=1 && arr[i-x]==1)oo=true;
            if(i+x<=n && arr[i+x]==1)oo=true;
            if(ok)ok=oo;
        }
    }
    if(!ok){
        cout<<-1<<endl;
        return ;
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


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e9;

#define mod             1e9+7
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
#define read(x)         freopen("in.txt","r",stdin);
#define write(x)        freopen("out.txt","w",stdout);
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define sz              3000005

string s;
int arr[100];

bool check(int n){

    for(int i=0; i<26; i++){
        if(arr[i] && arr[i]%n!=0)return false;
    }
    return true;
}

int main(){
    Fast;///using Fast I/O
    int a,b,c, i,j,k, t,n,m;

    cin>>t;
    while(t--){
        cin>>n;
        memset(arr,0,sizeof(arr));
        for(i=1; i<=n; i++){
            cin>>s;
            for(j=0; j<s.size(); j++){
                arr[s[j]-'a']++;
            }
        }
        if(check(n)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }

    return 0;
}


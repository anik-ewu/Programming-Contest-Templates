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

char ar[55][55];

void build(string s, int n){

    for(int i=0; i<=s.size()-n; i++){
        int k=0;
        for(int j=i; j<i+n; j++){
            ar[i][k++]=s[j];
        }
    }
}

void print(int n){

    for(int i=0; i<n; i++){
        cout<<ar[i][i];
    }
    cout<<endl;
}

int main(){
    Fast;///using Fast I/O
    int a,b,c, i,j,k, t,n,m;

    string s;

    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        build(s,n);
        print(n);
    }


    return 0;
}


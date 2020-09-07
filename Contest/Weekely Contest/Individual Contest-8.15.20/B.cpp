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

string solve(){

    int j=0;
    int len=5;
    string p="hello";

    for(int i=0; i<s.size(); i++){
        if(s[i]==p[j]){
            j++;
        }
        if(j==len)return "YES";
    }
    return "NO";
}

int main(){
    Fast;///using Fast I/O
    int a,b,c, i,j,k, t,n,m;

    cin>>s;
    cout<<solve()<<endl;


    return 0;
}


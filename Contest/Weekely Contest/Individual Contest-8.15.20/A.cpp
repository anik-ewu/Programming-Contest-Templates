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

int main(){
    Fast;///using Fast I/O
    int a,b,c, i,j,k, t,n,m;

    string s;
    cin>>s;
    int up,lo=0;
    for(i=0; i<s.size(); i++){
        lo+=(s[i]>='a' && s[i]<='z');
    }
    up=s.size()-lo;

    if(lo>=up){
        for(i=0; i<s.size(); i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i]=s[i]-'A'+'a';
            }
        }
    }
    else{

        for(i=0; i<s.size(); i++){
            if(s[i]>='a' && s[i]<='z'){
                s[i]=s[i]+'A'-'a';
            }
        }
    }
    cout<<s<<endl;

    return 0;
}


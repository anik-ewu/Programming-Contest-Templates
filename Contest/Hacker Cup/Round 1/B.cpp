#include<bits/stdc++.h>
using namespace std;

string s;

bool check(int n){

    int cnt1=0,cnt2=0;
    for(int i=0; i<s.size(); i++){
        cnt1+=(s[i]=='A');
        cnt2+=(s[i]=='B');
    }
    return abs(cnt1-cnt2)<=1;
}

int main(){

    freopen("alchemy_input.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int t,n,cs=1;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        cout<<"Case #"<<cs++<<": ";
        if(check(n))cout<<'Y'<<endl;
        else cout<<'N'<<endl;
    }

    return 0;
}

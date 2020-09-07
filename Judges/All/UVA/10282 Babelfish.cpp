#include<bits/stdc++.h>
#define sz         500005
#define ll         long long
#define FastRead   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std ;
char f,g;
bool flag;
string s,p;
map < string, string >mp;
int main(){

    FastRead
    ll int a,b,c, n,m, i,j,k,  q,l,r, sum,ans,mn,mx,cnt,cs=1;
    stringstream line;
    while(getline(cin,s)){
        if(s.size()==0)break;

        line.clear();
        line<<s;
        line>>s;
        line>>p;
       /// cout<<s<<' '<<p<<endl;
        mp[p]=s;
    }
    while(cin>>s){
        if(mp[s]=="")
            cout<<"eh"<<endl;
        else
            cout<<mp[s]<<endl;
    }



     return 0;
}


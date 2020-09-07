#include<bits/stdc++.h>
#define sz         19000000
#define ll         long long
#define FastRead   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std ;
string s,p;
vector < int >v;
vector < string >va,vstr;
int main(){

    ll int a,b,c, n,m, i,j,k,t,  q,l,r, sum,ans,mn,mx,cnt,cs=0;
    cin>>t;
    getchar();
    while(t--){
         getchar();
         getline(cin,s);
         getline(cin,p);
         int idx;
         stringstream line(s);
         while(line>>idx){
            va.push_back("0");
            v.push_back(idx);
         }

         stringstream line2(p);
         i=0;
         while(line2>>s){
            va[v[i++]-1]=s;
         }


         if(cs)
            cout<<endl;
         for(i=0; i<v.size(); i++)
            cout<<va[i]<<endl;
         v.clear();


        cs=1;
    }
     return 0;
}


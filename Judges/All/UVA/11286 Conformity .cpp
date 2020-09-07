#include<bits/stdc++.h>
#define FastRead   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std ;
vector <  int >v;
vector< int > vec[10005];
map < vector< int > , int >mp;
int main(){

    ///freopen("out.txt","w",stdout);
    FastRead
    int a,n,m, i,j, sum,mx;

    while(cin>>n){
        if(!n)break;
        mp.clear();
        v.clear();
        for(i=1; i<=n; i++)vec[i].clear();
        m=1;
        mx=-1;
        for(i=1; i<=n; i++){
            v.clear();
            for(j=1; j<=5; j++){
                cin>>a;
                v.push_back(a);
            }
            sort(v.begin(),v.end());
            mp[v]++;
            mx=max(mx,mp[v]);
            if(mp[v]==1){
                for(j=0; j<5; j++){
                    vec[m].push_back(v[j]);
                }
                m++;
            }
        }
        sum=0;
        for(i=1; i<m; i++){
            v=vec[i];
            if(mp[v]==mx)sum+=mx;
        }
        cout<<sum<<endl;
    }
     return 0;
}

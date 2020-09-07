#include<bits/stdc++.h>
#define sz         500005
#define ll         long long
#define FastRead   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std ;
char f,g;
bool flag;
string s,p;
vector < ll int >v,va;
ll int arr[sz],brr[sz];
unordered_map < int, int >mp;
int main(){

    FastRead
    ll int a,b,c, n,m, t,i,j,k,  q,l,r, sum,ans,mn,mx,cnt,cs=1;

    while(cin>>n){
        v.clear();
        va.clear();
        m=n;
        if(m<0)n*=-1;
        while(n){
            if(n%2)v.push_back(1);
            else v.push_back(0);
            n/=2;
        }
        reverse(v.begin(),v.end());

        while(v.size()<32){
            v.insert(v.begin()+0,0);
        }
        if(m<0){
          bool flag=false;
            for(i=31; i>=0; i--){
                if(flag)v[i]=(v[i]+1)%2;
                if(v[i])flag=true;

            }
        }
        for(i=24; i>=0; i-=8){
            for(j=i; j<i+8; j++)
                va.push_back(v[j]);
        }
        bool negative=false;
        if(va[0]){
           bool flag=false;
           negative=true;
            for(i=31; i>=0; i--){
                if(flag)va[i]=(va[i]+1)%2;
                if(va[i])flag=true;

            }
        }

        sum=0;
        for(i=1; i<32; i++){
            a=va[i]*pow(2,32-i-1);
            sum+=a;
        }
        cout<<m<<" converts to ";
        if(negative)
        cout<<'-';
        cout<<sum<<endl;
    }

     return 0;
}
///2147483648

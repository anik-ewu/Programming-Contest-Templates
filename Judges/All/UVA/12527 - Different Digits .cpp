#include<bits/stdc++.h>
#define sz         500005
#define ll         long long
#define FastRead   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std ;

char f,g;
bool flag;
string s,p;
map < ll int, ll int >mp;
vector < ll int >v,va;
ll int arr[sz],brr[sz];

bool check(int n){
    for(int i=0; i<10; i++)arr[i]=0;
    int x;
    while(n){
       x=n%10;
       n/=10;
       if(arr[x])return false;
       arr[x]++;
    }
    return true;
}

int main(){

    FastRead
    ll int t,i,j,k, n,m,a,b,c,l,r;

    while(cin>>l>>r){
      int cnt=0;
      while(l<=r){
        if(check(l)){
           cnt++;
        }
        l++;
     }
     cout<<cnt<<endl;
   }
     return 0;
}

///UVA :: 11933 Splitting Numbers
#include<bits/stdc++.h>
#define sz         500005
#define ll         long long
#define FastRead   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std ;
char f,g;
bool flag;
string s,p;
vector < ll int >v,va,vb;
ll int arr[sz],brr[sz];
unordered_map < int, int >mp;
int main(){

    FastRead
    ll int a,b,c, n,m, t,i,j,k,  q,l,r, sum,ans,mn,mx,cnt,cs=1;

    while(cin>>n){
        if(n==0)break;

        a=b=0;
        int mask=1;
        bool turn=1;
        for(i=0; i<32; i++){

            if(n&mask){
                if(turn){
                    a|=mask;
                }
                else{
                    b|=mask;
                }
                turn=!turn;
            }
            mask<<=1;
        }
        cout<<a<<' '<<b<<endl;
    }

     return 0;
}
///2147483648

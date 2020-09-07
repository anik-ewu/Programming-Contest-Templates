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

int divs(int n, int num){

    int mn=num;
    for(int i=1; i<=sqrt(num); i++){
        if(num%i==0){
            if((n-1)*i>=num)mn=min(mn,i);
            if((n-1)*(num/i)>=num){
                mn=min(mn,(num/i));
            }
        }

    }
    return mn;
}

int main(){
    Fast;///using Fast I/O
    int a,b,c, i,j,k, t,n,m,x,y;

    cin>>t;
    while(t--){
        cin>>n;
        cin>>x>>y;
        if(n==2){
            cout<<x<<' '<<y<<endl;
        }
        else{
           int num=divs(n,y-x);
           vector< int > v;
           i=y;
           while(i>=1 && n){
            v.push_back(i);
            i-=num;
            n--;
           }
           i=y+num;
           while(n){
            v.push_back(i);
            i+=num;
            n--;
           }
           for(i=0; i<v.size(); i++){
            cout<<v[i]<<' ';
           }
           cout<<endl;
        }
    }







    return 0;
}


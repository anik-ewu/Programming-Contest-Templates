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

int solve(){

    int sum=0;
    int cnt=0;
    priority_queue< int > pq;

    for(int i=0; i<s.size(); i++){
        if(s[i]=='0' and cnt){
            pq.push(cnt);
            cnt=0;
        }
        else if(s[i]=='1'){
            cnt++;
        }
    }
    if(cnt)pq.push(cnt);


    while(!pq.empty()){
        sum+=pq.top();
        pq.pop();
        if(!pq.empty())pq.pop();
    }
    return sum;

}

int main(){
    Fast;///using Fast I/O
    int a,b,c, i,j,k, t,n,m;

    cin>>t;
    while(t--){
        cin>>s;
        cout<<solve()<<endl;
    }

    return 0;
}


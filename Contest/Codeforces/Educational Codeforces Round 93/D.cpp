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

priority_queue< int >r,g,bb;

ll solve(int i, int j, int k){

    ll a,b,c,sum=0;
    while(r.size()<len)r.push(0);
    while(g.size()<len)g.push(0);
    while(bb.size()<len)bb.push(0);
    r.push(0);
    g.push(0);
    bb.push(0);
    while(true){
        a=r.top();
        b=g.top();
        c=bb.top();
        int cnt=2;
        int mn=min(a,min(b,c));
        if(r.top()!=mn)r.pop(),cnt--;
        if(g.top()!=mn)g.pop(),cnt--;
        if(bb.top()!=mn)bb.pop(),cnt--;

        if(r.top()==mn && cnt)r.pop(),cnt--;
        if(g.top()==mn && cnt)g.pop(),cnt--;
        if(bb.top()==mn && cnt)bb.pop(),cnt--;


        ll add;
        if(a==mn)add=b*c;
        else if(b==mn)add=a*c;
        else if(c==mn)add=a*b;
        if(add==0)return sum;
        sum+=add;
    }
}


int main(){
    Fast;///using Fast I/O
    int a,b,c, i,j,k, t,n,m;
    cin>>n>>m>>k;
    for(i=1; i<=n; i++){
        cin>>a;
        r.push(a);
    }
    for(i=1; i<=m; i++){
        cin>>a;
        g.push(a);
    }

    for(i=1; i<=k; i++){
        cin>>a;
        bb.push(a);
    }
    cout<<solve(max(n,max(m,k)))<<endl;


    return 0;
}


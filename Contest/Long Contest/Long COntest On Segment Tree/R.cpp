#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz  100005
#define mod 1000000007
int L,R;
ll arr[sz],brr[sz];

struct st{
    ll a,b;
}tree[4*sz],lazy[4*sz];
vector < st > vs;
struct st combine(st L, st R){
    ll x=(L.a*R.a)%mod;
    ll y=__gcd(L.b,R.b)%mod;
    return{x,y};
};

void build(int at, int l, int r){
    if(l==r){
        tree[at]={brr[l],brr[l]};
        return;
    }
    int mid=(l+r)/2;
    build(at*2,l,mid);
    build(at*2+1,mid+1,r);
    tree[at]=combine(tree[at*2],tree[at*2+1]);
}

void update(int at, int l, int r){
    //move(at,l,r);
    if(R<l || r<L)return;
    if(L<=l && r<=R){

    }

}

void query(int at, int l, int r){

    if(R<l || r<L)return;
    if(L<=l && r<=R){
        vs.push_back(tree[at]);
    return;
    }
    int mid=(l+r)/2;
    query(at*2,l,mid);
    query(at*2+1,mid+1,r);
}
ll modinv(ll b, ll p){
    if(p==0)return 0;
    if(p%2) return ((b%mod)*(modinv(b,p-1))%mod)%mod;
    else    return (((modinv(b,p/2))%mod)*((modinv(b,p/2))%mod))%mod;
}

int lcm(int i){

    ll x=__gcd(arr[i-1],arr[i]);
    ll y=((((brr[i-1]%mod)*arr[i])%mod)*(x,mod-2))%mod;
    arr[i]=x;
    return y%mod;
}

int main(){

    int n,m,l,r,i,tp,val;
    cin>>n>>m;
    for(i=1; i<=n; i++){
        cin>>arr[i];
        if(i==1)brr[i]=arr[i];
        else{
            brr[i]=lcm(i);
        }
        cout<<brr[i]<<' ';
    }
    cout<<endl;
    build(1,1,n);
    while(m--){
        cin>>tp>>L>>R;
        if(tp==0){
            cin>>val;
            //update(1,1,n,val);
        }
        if(tp){
            vs.clear();
            query(1,1,n);
            cout<<vs.size()<<endl;
            ll gc,lcm;
            gc=vs[0].b;
            lcm=vs[0].a;;
            for(i=1; i<vs.size(); i++){
                gc=__gcd(gc,vs[i].b)%mod;
                lcm=((lcm*vs[i].a)%mod);//*(modinv(gcd,mod-2)%mod))%mod;
                ///cout<<vs[i].a<<' '<<vs[i].b<<endl;
            }
            //lcm=(((lcm*vs[i].a)%mod)*(modinv(gc,mod-2)%mod))%mod;
            cout<<lcm/gc<<' '<<gc<<endl;
        }

    }



    return 0;
}

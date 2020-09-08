///Date: 29/5/2020

typedef long long ll;

ll binpow(ll b, ll p , ll m){
    if(p==0)return 1;
    ll res=binpow(b,p/2,m);
    res=(res*res)%m;
    if(p%2==1) res=(res*b)%m;
    return res;
}

int main(){

    int a, b, m;
    cin>>a>>b>>m;

    cout<<binpow(a,b,m)<<endl;

}

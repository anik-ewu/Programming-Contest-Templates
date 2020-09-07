///Date     :7.7.2020
///Approach :Matrix Exponentiation

#include<bits/stdc++.h>
using namespace std;

int MOD;
typedef long long ll;
typedef vector< ll> vmat1;
typedef vector< vector<ll> > vmat;

struct Matrix{

    vmat mat;
    ll row, col;

    Matrix() {}
    Matrix(vector<vector<ll> > values): mat(values), row(values.size()),
        col(values[0].size()) {}

    Matrix Identity_Matrix(ll n){
        vmat value(n,vmat1(n,0));
        for(ll i=0; i<n; i++)
            value[i][i]=1;
        return value;
    }

    Matrix zero_Matrix(){
        vmat value(row,vmat1(col,0));
        return value;
    }

    Matrix operator*(Matrix other){
        ll n=row,m=other.col;
        vmat res(n,vmat1(m,0));
        for(ll i=0; i<n; i++)
            for(ll j=0; j<m; j++)
                for(ll k=0; k<col; k++)
                    res[i][j]=(res[i][j]+(mat[i][k]*other.mat[k][j])%MOD)%MOD;
        return res;
    }

    Matrix operator+(Matrix other){
        ll n=row,m=col;
        vmat res(n,vmat1(m,0));
        for(ll i=0; i<n; i++)
            for(ll j=0; j<m; j++)
                res[i][j]=(mat[i][j]+other.mat[i][j])%MOD;
        return res;
    }

    Matrix power(ll k){
        if(k==1)
            return mat;
        Matrix x=power(k/2);
        x=(x*x);
        return (k&1)?x*mat:x;
    }
};


int main(){

    ll a1,b1,c1;
    ll a2,b2,c2;
    ll f[3],g[3];
    ll q, t, n,ansf,ansg,i,j, cs=1;
    cin>>t;
    while(t--){
        cin>>a1>>b1>>c1;
        cin>>a2>>b2>>c2;

        for(i=0; i<3; i++)cin>>f[i];
        for(i=0; i<3; i++)cin>>g[i];

        vmat base({{a1,b1,0,0,0,c1}, {1,0,0,0,0,0},{0,1,0,0,0,0},
                  {0,0,c2,a2,b2,0}, {0,0,0,1,0,0},{0,0,0,0,1,0}});
        vmat temp({{f[2]},{f[1]},{f[0]},{g[2]},{g[1]},{g[0]}});
        Matrix M(base),res;

        cin>>MOD>>q;
        cout <<"Case "<<cs++<<":"<<endl;

        while(q--){
            cin>>n;
            if(n<=2){
                cout<<f[n]%MOD<<' '<<g[n]%MOD<<endl;
            }
            else{
                res=M.power(n-2);
                res=res*temp;
                cout<<res.mat[0][0]<<' '<<res.mat[3][0]<<endl;
            }
        }
    }
    return 0;
}


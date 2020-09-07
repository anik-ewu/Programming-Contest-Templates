///Date     : 1.7.2020
///Approach : Matrix exponential with I matrix

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod;
ll Pow[22];

void mul(int A[2][2], int B[2][2]){

    int res[3][3];
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            res[i][j]=0;
            for(int k=0; k<2; k++){
                ll x=(A[i][k]*1LL*B[k][j])%mod;
                res[i][j]=(res[i][j]+x)%mod;
            }
        }
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            A[i][j]=res[i][j];
        }
    }
}

int power(ll n){

    int F[2][2]={{1,1}, {1,0}};
    int I[2][2]={{1,0}, {0,1}};

    while(n){
        if(n%2)
            mul(I,F),n--;
        else
            mul(F,F),n/=2;
    }
    return (I[0][0])%mod;
}

int nthterm(ll n){
    if(n==0)return 0;
    if(n==1)return 1;
    return power(n-1);
}

void cal(int n){
    for(int i=0; i<n; i++){
     Pow[i]=(1<<i);
    }
}

int main(){

    cal(21);///calculation pow(2^i) i= { 0...20 }

    ll n,m;
    while(scanf("%lld%lld",&n,&m)==2){
        mod=Pow[m];
        printf("%d\n",nthterm(n));
    }
    return 0;
}

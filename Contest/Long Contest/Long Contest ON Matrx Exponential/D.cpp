///Date     : 7.7.2020
///Approach : Matrix Exponentiation

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod;
int Pow[5];

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

int power(int a, int b, int n){

    int F[2][2]={{1, 1}, {1, 0}};
    int I[2][2]={{1,0}, {0,1}};

    while(n){
       if(n%2)
            mul(I,F),n--;
       else
            mul(F,F),n/=2;
    }
    return (I[0][0]*1LL*b+I[0][1]*1LL*a)%mod;
}

int fibo(int a, int b, int n, int m){
    mod=Pow[m];
    if(n==0)return a%mod;
    if(n==1)return b%mod;
    return power(a, b, n-1);
}


int main(){

    Pow[1]=10;Pow[2]=100;Pow[3]=1000;Pow[4]=10000;

    int t,a,b,n,m,cs=1;
    scanf("%d",&t);
    while(t--){
       scanf("%d%d%d%d",&a,&b,&n,&m);
       printf("Case %d: %d\n",cs++,fibo(a,b,n,m));
    }
    return 0;
}

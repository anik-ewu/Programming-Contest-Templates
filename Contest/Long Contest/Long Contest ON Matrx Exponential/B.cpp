///Date     : 1.7.2020
///Approach : Matrix exponential

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod;

ll power(int F[2][2], ll n){
    int M[2][2]={{1,1}, {1,0}};

    if(n==1)return F[0][0];

    power(F, n/2);
    multiply(F,F);
    if(n%2)multiply(F,M);

    return

}

ll findnth(ll n){
    int F[2][2]={{1,1}, {1,0}};
    if(n==0)return 0;
    if(n==1)return 1;
    return power(F, n-1)%mod;
}

int main(){
    ll n;
    while(cin>>n>>mod){
        mod=powl(2,mod);
        cout<<findnth(n)<<endl;
    }

    return 0;
}

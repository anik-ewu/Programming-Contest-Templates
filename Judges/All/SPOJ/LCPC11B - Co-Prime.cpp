///Date     : 24.6.2020
///Approach : Inclusion exclusion Principle
/*
Let's solve the inverse problem-compute the number that are not co-primes with n.
We will denote the prime factors of n, as pi.
How many numbers in the interval [1;r], are divisible by pi? The answer to this question is: r/pi
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define S 10000002

bool mark[S+7];
vector < int > prime;
vector < ll > factor;

void  sieve(){
    memset(mark,0,sizeof(mark));
    for(int i=4; i<=S; i+=2)mark[i]=1;
    for(int i=3; i*i<=S; i+=2){
        if(mark[i]==0){
            for(int j=i*i; j<S; j+=(i*2))
                mark[j]=1;
        }
    }
    prime.push_back(2);
    for(int i=3; i<=S; i+=2){
        if(mark[i]==0)
            prime.push_back(i);
    }
}

void PRIME_FACTOR_OF_N(ll n){
    for(int i=0; prime[i]*prime[i]<=n; i++){
        if(n%prime[i]==0){
            factor.push_back(prime[i]);
            while(n%prime[i]==0)
                n/=prime[i];
        }
    }
    if(n>1)factor.push_back(n);
}

ll solve(ll N){
    ll sum=0;
    int len=factor.size();
    for(int mask=1; mask<(1<<len); mask++){
        ll mul=1;
        for(int i=0; i<len; i++){
            if(mask&(1<<i)){
               mul=mul*factor[i];
            }
        }
        if(__builtin_popcount(mask)%2) sum+=(N/mul);
        else sum-=(N/mul);
    }
    return sum;
}

int main(){

    sieve();

    ll tot,a,b,n,t,cs=1;
    cin>>t;
    while(t--){
        cin>>a>>b>>n;
        factor.clear();
        PRIME_FACTOR_OF_N(n);
        ll total=b-solve(b)-(a-1)+solve(a-1);
        cout<<"Case #"<<cs++<<": "<<total<<endl;
    }
    return 0;
}

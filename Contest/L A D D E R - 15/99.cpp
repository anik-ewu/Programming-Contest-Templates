///2.28.2020
///Idea : We don't need to consider up to 2. 10^9 as the value of of Xi<=10^7
///Steps: Find the factors of the numbers, map them and finally prefix sum to answer the queries
#include<bits/stdc++.h>
using namespace std;
#define sz 10000006

bool mark[sz];
int brr[sz];
vector < int > prime;


void sieve(){
    int i,j;
    memset(mark,0,sizeof(mark));

    for(i=4; i<sz; i+=2)mark[i]=1;
    for(i=3; i*i<sz; i+=2){
        for(j=i*i; j<sz; j+=(i*2))
            mark[j]=1;
    }
    prime.push_back(2);
    for(i=3; i<sz; i+=2){
        if(mark[i]==0)
            prime.push_back(i);
    }
}
void factors(int n){

    for(int i=0; i<prime.size() && prime[i]*prime[i]<=n; i++){
        if(n%prime[i]==0){
            brr[prime[i]]++;
            while(n%prime[i]==0){
                n/=prime[i];
            }
        }
    }
    if(n>1)brr[n]++;///another prime factor
}


int main(){

    sieve();
    int val,n,i,q,l,r;
    scanf("%d",&n);
    for(i=1; i<=n; i++){
        scanf("%d",&val);
        factors(val);///precompute with prime factor
    }
    ///cumulative sum
    for(i=2; i<sz; i++){
        brr[i]+=brr[i-1];
    }

    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&l,&r);
        l=min(l,sz-6);
        r=min(r,sz-6);
        printf("%d\n",brr[r]-brr[l-1]);
    }

    return 0;
}



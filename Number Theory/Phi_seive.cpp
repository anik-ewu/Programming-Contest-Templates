#include<iostream>
#include<cstdio>
using namespace std;

#define S 5000050
typedef unsigned long long int ll;

ll phi[S];
int mark[S];

void phii(){
    int i,j;
    for(i=2; i<S; i++){
        phi[i]=i;
        mark[i]=0;
    }
    for(i=2; i<S; i++){
        if(mark[i]==0){
            for(j=i; j<S; j+=i){
                mark[j]=1;
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
}

int main(){
    phii();
    ll a,b,c,i,j,t;
    cin>>t;
    for(i=1; i<=t; i++){
        cin>>a;
        cout<<phi[a]<<endl;
    }
    return 0;
}


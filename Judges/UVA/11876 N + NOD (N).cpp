#include<bits/stdc++.h>
using namespace std;

#define S 10000002

int cum[S];
int arr[S];
bool mark[S+7];
vector < int > prime;

void  sieve(){
    int i,j,k,x;

    for(int i=1; i<S; i++)
        mark[i]=true;
    mark[1]=false;
    for(i=4; i<=S; i+=2)
        mark[i]=false;
    for(i=3; i*i<=S; i+=2){
        if(mark[i]==true){
            for(j=i*i; j<S; j+=i+i)
                mark[j]=false;
        }
    }
    prime.push_back(2);
    for(i=3; i<=S; i+=2){
        if(mark[i]==true)
            prime.push_back(i);
    }
}

int divisor(int n){
    cout<<n<<endl;
    int i,val,con,sum;
    sum=1;
    for(i=0; prime[i]*prime[i]<=n; i++){
        if(n%prime[i]==0){
            con=0;
            while(n%prime[i]==0){
                con++;
                n/=prime[i];
            }
            sum*=(con+1);
        }
    }
    if(n>1){
        sum*=2;
    }
    return sum;

}

void precal(){

    arr[0]=1;
    for(int i=1; i<=10; i++){
        arr[i]=(arr[i-1])+divisor(arr[i-1]);
        cout<<arr[i]<<endl;
    }

}


int main(){

    sieve();
    precal();
    cout<<prime.size();


    return 0;
}

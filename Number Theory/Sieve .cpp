#include<bits/stdc++.h>
using namespace std;
#define N 100002
bool mark[N+7];
vector < int > v;
void  sieve(){
    memset(mark,0,sizeof(mark));
    for(int i=4; i<=N; i+=2)mark[i]=1;
    for(int i=3; i*i<=N; i+=2){
        if(mark[i]==0){
            for(int j=i*i; j<N; j+=(i*2))
                mark[j]=1;
        }
    }
    v.push_back(2);
    for(int i=3; i<=N; i+=2){
        if(mark[i]==0)
            v.push_back(i);
    }
}

int main(){
    sieve();

    cout<<v.size()<<endl;





    cout<<v.size();
}

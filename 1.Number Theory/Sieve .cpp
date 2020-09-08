#include<bits/stdc++.h>
using namespace std;
#define S 10000002
bool mark[S+7];
vector < int > v;
void  seive(){
    memset(mark,0,sizeof(mark));
    for(int i=4; i<=S; i+=2)mark[i]=1;
    for(int i=3; i*i<=S; i+=2){
        if(mark[i]==0){
            for(int j=i*i; j<S; j+=(i*2))
                mark[j]=1;
        }
    }
    v.push_back(2);
    for(int i=3; i<=S; i+=2){
        if(mark[i]==0)
            v.push_back(i);
    }
}

int main(){
    seive();
    cout<<v.size();
}

///Date     : 1.5.2020
///Tags     : Number Theory + Binary Search
///Idea     : ***
///Comments : Just because someone stumbles, loses their way, doesn't mean they lost forever.

#include<bits/stdc++.h>
using namespace std;

vector < int > v;

void build(int a, int b){

    int n=sqrt(a)+1;

    for(int i=1; i<=n; i++){
        if(a%i==0){
          if(b%i==0)v.push_back(i);
          if(b%(a/i)==0)v.push_back(a/i);
        }
    }
    sort(v.begin(),v.end());
}

int main(){

    int i,n,a,b,l,r;
    cin>>a>>b;
    if(a>b)swap(a,b);
    build(a,b);
    cin>>n;
    while(n--){
        cin>>l>>r;
        int idx=upper_bound(v.begin(),v.end(),r)-v.begin()-1;
        if(v[idx]<l || v[idx]>r)cout<<-1<<endl;
        else cout<<v[idx]<<endl;
    }


    return 0;
}


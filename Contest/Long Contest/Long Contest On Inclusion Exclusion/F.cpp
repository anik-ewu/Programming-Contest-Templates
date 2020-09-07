#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz 1e14

vector < int > v;

void PRECAL_SQUARE_NUMBER(){

    ll i=2;
    while(i*i<=sz){
        v.push_back((i*i));

    }
    cout<<v.size()<<endl;
}

int main(){

    PRECAL_SQUARE_NUMBER();
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;

    }

    return 0;
}

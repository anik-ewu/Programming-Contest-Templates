#include<bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int i,j,n,t,a,b,c,cs=1;
    cin>>t;

    while(t--){
        cin>>a>>b;
        int tot=0;
        for(i=3; i<=9; i++){
            cin>>c;
            tot+=c;
        }
        cout<<"Case "<<cs++<<": "<<a-tot<<endl;
    }



    return 0;
}

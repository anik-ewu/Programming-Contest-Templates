#include<bits/stdc++.h>
using namespace std;

int main(){

    ///freopen("out.txt","w",stdout);

    int ans,i,j,k;
    k=(1*(11+(11-3)))%(11+3);
    cout<<k<<endl;
    for(i=11; i<=1000; i++){
        for(j=3; j<=1000; j++){
            int c=1;
            k=(c*(i+(i-j)))%(i+j);
            if(k!=0)cout<<c<<' '<<i<<' '<<j<<endl;

        }
    }

    return 0;
}

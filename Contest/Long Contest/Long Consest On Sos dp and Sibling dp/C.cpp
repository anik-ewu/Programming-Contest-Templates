#include<bits/stdc++.h>
using namespace std;

int main(){

    long long n, x, y, mul, temp=0, cnt=0;

    cin>>x>>y;

    mul=x*y;
    if(mul==0){
        cout<<0<<endl;
        return 0;
    }
    while(y!=mul){
        if(y+y<=mul){
            y+=y;
        }
        else{
            if(temp==0)temp=y;
            while(y+temp>mul){
                temp=temp/2;
            }
            y+=temp;
        }
        cnt++;
    }

    long long ans=cnt;
    cnt=0;

    y=x;
    temp=0;
    while(y!=mul){
        if(y+y<=mul){
            y+=y;
        }
        else{
            if(temp==0)temp=y;
            while(y+temp>mul){
                temp=temp/2;
            }
            y+=temp;
        }
        cnt++;
    }

    ans=min(ans,cnt);
    cout<<ans<<endl;

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int big_mod(long long int base, long long int power, long long int mod)
{
    if(power==0)
        return 1;
    //কোন কিছুর power 0 হলে তার মান 1 হয়ে যায়
    else if(power%2==1) //power বেজোড় হলে
    {
        int p1 = base % mod;
        int p2 = (big_mod(base,power-1,mod))%mod;
        return (p1*p2)%mod;
    }
    else if(power%2==0) //power জোড় হলে
    {
        int p1 = (big_mod(base,power/2,mod))%mod;
        return (p1*p1)%mod;
    }
}


int main()
{
    string s;
    char p;
    long long int a,b,c,x;
    cin>>s;

    p=s[s.size()-1];
    a=p-'0';
    if(s.size()>1)
    {

        p=s[s.size()-2];
        x=p-'0';
        x*=10;
        x+=a;
        a=x;
    }
    if(a%4==0)
        cout<<4<<endl;
    else
        cout<<0<<endl;
    return 0;
}

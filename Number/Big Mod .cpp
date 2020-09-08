#include<bits/stdc++.h>
using namespace std;
int big_mod(long long int base, long long int power, long long int mod)
{
    if(power==0)    return 1;
    ///কোন কিছুর power 0 হলে তার মান 1 হয়ে যায়
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
    long long int base,power,mode;
    while(cin>>base>>power>>mode)
    {
        cout<<big_mod(base,power,mode)<<endl;
    }
    return 0;
}

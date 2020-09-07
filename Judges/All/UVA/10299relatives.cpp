#include<iostream>
using namespace std;
long long int phi(long long int n)
{
    long long int phi=n;
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n/=i;
            }
            phi-=phi/i;
        }
    }
    if(n>1)
    {
        phi-=phi/n;
    }
    return phi;

}
int main()
{
    long long int a;
    while(cin>>a)
    {
        if(a==0)break;
        cout<<phi(a)<<endl;
    }
    return 0;
}

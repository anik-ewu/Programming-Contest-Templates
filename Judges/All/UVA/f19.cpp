#include<iostream>
using namespace std;
int f91(int);
int main()
{
    long long int n,a,k;
    k=250000;
    while(k>0)
    {
        cin>>n;
        if(n==0){break;}
        a=n;
        cout<<"f91("<<a<<") = ";
        cout<<f91(n)<<endl;
        k--;
    }
    return 0;
}
int f91(int n)
{
    if (n<101)
    {
        return 91;
    }
    else
    {
        return n-10;
    }

}

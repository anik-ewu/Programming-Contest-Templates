#include<iostream>
using namespace std;
int main()
{
    int n,a,b,c,i,j,k;
    cin>>n;
    while(n>0)
    {
        cin>>a>>b;
        i=a/3;
        j=b/3;
        k=i*j;
        cout<<k<<endl;
        n--;

    }
    return 0;
}

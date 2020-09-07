#include<iostream>
using namespace std;
main()
{
    long long int a[10],b,n,c,d;
    cin>>n;
    while(n>0)
    {
    for(b=1; b<=3; b++)
    cin>>a[b];

    for(b=1; b<=3; b++)
        for(c=b+1; c<=3; c++)
        {
            if(a[b]<a[c])
            {
                d=a[b];
                a[b]=a[c];
                a[c]=d;
            }
        }
        if(a[1]<a[2]+a[3]){cout<<"OK"<<endl;}
        else{cout<<"Wrong!!"<<endl;}
        n--;
    }
}

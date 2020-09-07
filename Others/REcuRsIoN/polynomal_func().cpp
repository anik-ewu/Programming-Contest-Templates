#include<iostream>
using namespace std;
int polyno(int i,int n)
{
    if(i<n)
    {

        if(i==0)
        {
            cout<<'1'<<endl;
        }
        else
        {
            cout<<" + x";
            if(i>1)
                cout<<'^'<<i;
        }
        polyno(i+1,n);
    }
}
int main()
{
    int a;
    while(cin>>a)
    {
        cout<<polyno(1,a);
    }
}

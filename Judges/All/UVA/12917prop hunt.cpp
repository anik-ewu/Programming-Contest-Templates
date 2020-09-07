#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d;
    while(cin>>a>>b>>c)
    {
        d=c-b;
        if(d<a)
            cout<<"Hunters win!"<<endl;
        else
            cout<<"Props win!"<<endl;

    }
    return 0;
}

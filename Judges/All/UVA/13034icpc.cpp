#include<iostream>
using namespace std;
int main()
{
    int a,c,d,i,n;
    while(cin>>n)
    {
    c=1;
    while(n>0)
    {
        d=0;
        for(i=1; i<=13; i++)
        {
            cin>>a;
            if(a<1)
            {
                d=-1;
            }
        }
        if(d!=-1)
        {
            cout<<"Set #"<<c<<": Yes"<<endl;
        }
        else
        {
            cout<<"Set #"<<c<<": No"<<endl;
        }

        n--;
        c++;
    }
}
return 0;
}

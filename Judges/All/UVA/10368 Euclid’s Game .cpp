#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,x,y,i,j;
    while(cin>>a>>b)
    {
        x=0;

        if(a==0 && b==0)
            break;
        while(true)
        {
            x++;
            if(a<b)
                swap(a,b);
            if(a%b==0)
                break;
            x=a/b;
            y=x*b;
            a-=x;
        }
        if(x%2==1)
            cout<<"Stan wins"<<endl;
        else
            cout<<"Ollie wins"<<endl;
    }
    return 0;
}

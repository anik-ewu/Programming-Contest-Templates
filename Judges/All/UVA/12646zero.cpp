#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,e,f;
    while(cin>>a>>b>>c)
    {
        if(a==b && b==c)
            cout<<'*'<<endl;
        else if(a==b)
            cout<<'C'<<endl;
        else if(b==c)
            cout<<'A'<<endl;
        else
            cout<<'B'<<endl;
    }
    return 0;
}

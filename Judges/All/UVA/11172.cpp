#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,c;
    cin>>c;
    while(c>0)
    {
        cin>>a>>b;
        if(a>b){cout<<">"<<endl;}
        else if(a<b){cout<<"<"<<endl;}
        else{cout<<"="<<endl;}
        c--;
    }
    return 0;
}

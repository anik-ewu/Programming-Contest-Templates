#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,d;
    cin>>x>>y;

    d=y*log10(x);
    d+=1;
    cout<<pow(x,y)<<' '<<d<<endl;
}

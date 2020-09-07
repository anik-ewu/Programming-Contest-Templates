#include<bits/stdc++.h>
using namespace std;
int main()
{

    int i,j,k,x,y,z,a=0,b=0,c=0,d=0,e=0,f=0;
    string s;
    cin>>k>>s;
    f=6-k;
    for(i=0; i<s.size(); i++)
    {
        if(s[i]>='A' && s[i]<='Z')
            a=1;

        else if(s[i]>='a' && s[i]<='z')
            b=1;

        else if(s[i]>='0' && s[i]<='9')
            c=1;
        else
            d=1;
    }
    x=0;
    if(a==0)
        x++;

    if(b==0)
        x++;

    if(c==0)
        x++;
    if(d==0)
        x++;
    while(k+x<6)
        x++;
    cout<<x<<endl;
    return 0;

}

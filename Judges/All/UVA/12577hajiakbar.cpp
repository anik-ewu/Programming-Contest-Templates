#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x=1;
    char a[15];
    while(gets(a))
    {
        if(a[0]=='*'){break;}
        if(strcmp(a,"Hajj")==0){cout<<"Case "<<x<<": "<<"Hajj-e-Akbar"<<endl;x++;}
        else if(strcmp(a,"Umrah")==0){cout<<"Case "<<x<<": "<<"Hajj-e-Asghar"<<endl;x++;}
    }
    return 0;
}


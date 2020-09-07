#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b[10],c,d,e,f,g,i;
    while(cin>>a)
    {
        e=0;
        for(i=1; i<=5; i++)
        {
            cin>>b[i];
            if(b[i]==a){e++;}
        }
        cout<<e<<endl;
    }
    return 0;
}

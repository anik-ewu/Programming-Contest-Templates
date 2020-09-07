#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,a;
    while(cin>>n)
    {
        if(n==0)
            break;
        j=0;
        for(i=1; i<=n; i++)
        {
            cin>>a;
            if(a%2==0)
                j=1;
        }
        if(j==0 && n>1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }



    return 0;
}



1 1 1 1 =*
2 2 1 1 = *

2 2 2 1 1 1= *

2 2 1 1 1=*
1 1 1 1 1=0

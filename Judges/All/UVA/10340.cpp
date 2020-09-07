#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,x,y,z,c,k;
    char a[100000],b[100000];
    while(cin>>a)
    {
        gets(b);
        c=strlen(a);
        k=strlen(b);
        j=0;
        for(i=0; i<k; i++)
        {
            if(a[j]==b[i])
            {
                j++;
                c--;
            }
            if(c==0)break;
        }
        if(c==0)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}

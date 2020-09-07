#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,x,y,z,b,c,n;
    char a[100000];
    cin>>n;
    getchar();
    while(n>0)
    {
        gets(a);
        k=strlen(a);
        b=sqrt(k);
        c=b*b;
        if(c!=k)
            cout<<"INVALID"<<endl;
        else
        {
            z=0;
            while(z<b)
            {
                y=z;
                while(y<k)
                {
                    cout<<a[y];
                    y+=b;
                }
                z++;

            }
            cout<<endl;
        }
        n--;
    }
    return 0;
}

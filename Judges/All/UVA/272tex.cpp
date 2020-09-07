#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,x=0;
    char a[100000];
    while(gets(a))
    {
        k=strlen(a);
        for(i=0; i<k; i++)
        {
            if(int(a[i])==34 && x==0)
            {
                cout<<"``";
                x=1;
            }

            else if(int(a[i])==34 && x==1)
            {
                cout<<"''";
                x=0;
            }
            else
                cout<<a[i];
        }
        cout<<endl;
    }

return 0;
}

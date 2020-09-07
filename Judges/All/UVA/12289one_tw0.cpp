#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[10];
    int b,c,n,i,j,k;
    cin>>n;
    getchar();
    while(n>0)
    {
        gets(a);
        c=strlen(a);
        if(c==3)
        {
            if(a[0]=='t' && a[1]=='w' || a[0]=='t' && a[2]=='o' || a[1]=='w' && a[2]=='o'){cout<<"2"<<endl;}
            else{cout<<"1"<<endl;}
        }
        else{cout<<"3"<<endl;}
        n--;
    }
    return 0;
}

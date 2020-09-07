#include<bits/stdc++.h>
using namespace std;
char arry[500],arry2[500];
int v[500];
void init()
{
    for(int i=0; i<300; i++)
    {
        arry[i]='0';
        arry2[i]='0';
        v[i]=0;
    }
}

int main()
{
    string s,p,q;
    int n,i,j,x,y,a,b,c;
    cin>>n;
    while(n--)
    {
        cin>>s>>p;
        reverse(s.begin(),s.end());
        reverse(p.begin(),p.end());

        init();

        i=0;
        while(s[i]=='0')
            i++;
        j=s.size();
        j--;
        while(s[j]=='0')
            j--;
        y=1;
        for(x=i; x<=j; x++)
            arry[y++]=s[x];


        i=0;
        while(p[i]=='0')
            i++;
        j=p.size();
        j--;
        while(p[j]=='0')
            j--;
        y=1;
        for(x=i; x<=j; x++)
            arry2[y++]=p[x];

        j=1;
        int k=0;
        for(i=0; i<=210; i++)
        {
            a=arry[i]-'0';
            b=arry2[i]-'0';
            c=a+b+k;
            if(c>9)
                k=c/10;
            else
                k=0;
            v[j++]=c%10;
        }
        a=j;
        i=0;
        while(v[i]==0)
            i++;
        j=a;
        j--;
        while(v[j]==0)
            j--;
        y=1;
        for(x=i; x<=j; x++)
            cout<<v[x];
        cout<<endl;
    }
    return 0;
}





/*
3
24 1
4358 754
305 794
*/

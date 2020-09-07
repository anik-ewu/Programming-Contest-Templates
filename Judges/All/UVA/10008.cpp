#include<bits/stdc++.h>
using namespace std;
int a[26];
int main()
{
    int i,j,k,l,m,c,n;
    char p[26]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char q[100000];
    cin>>n;
    getchar();
    for(i=1; i<=n; i++)
    {
        gets(q);
        k=strlen(q);
        for(j=0; j<k; j++)
        {
            for(l=0; l<26; l++)
            {
                if(q[j]==p[l] || q[j]-'a'+'A'==p[l])
                {
                    a[l]++;
                    break;
                }
            }
        }
    }
    c=0;
    int s=0;
    for(l=0; l<26; l++)
        if(a[l]!=0)s++;
    for(l=1; l<=s; l++)
    {
        for(j=0; j<26; j++)
        {
            if(c<a[j])
            {
                c=a[j];
                m=j;
            }
        }
        cout<<p[m]<<' '<<c<<endl;
        a[m]=0;
        c=0;
    }
    return 0;
}


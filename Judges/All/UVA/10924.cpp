#include<bits/stdc++.h>
using namespace std;
int siv(int x);
int main()
{
    long long int i,j,k,c,d,e,f;
    char b[27]= {'1','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char a[50];
    while(gets(a))
    {
        c=strlen(a);
        f=0;
        for(i=0; i<c; i++){
            for(j=1; j<=26; j++)
                if(a[i]==b[j] && a[i]!='1')
                {
                    f=f+j;
                    a[i]='1';
                }
                else if(a[i]+'a'-'A'==b[j] && a[i]!='1')
                {
                    f=f+j+26;
                    a[i]='1';
                }
        }
        e=siv(f);
        if(e==1)
        cout<<"It is a prime word."<<endl;
        else
        cout<<"It is not a prime word."<<endl;
    }
    return 0;
}
int siv(int x)
{
    int i;
    for(i=2; i*i<=x; i++)
        if(x%i==0)
          return 0;
        return 1;

}

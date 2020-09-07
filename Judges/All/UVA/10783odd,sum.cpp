#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,c,d,e,f=1,i,x;
    cin>>n;
    while(n>0)
    {
      cin>>a>>b;
      c=0;
      for(i=a; i<=b; i++)
      {
          if(i%2!=0){c=c+i;}
      }
      cout<<"Case "<<f<<": "<<c<<endl;
    n--;
    f++;
    }
    return 0;
}

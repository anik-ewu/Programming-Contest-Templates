#include<bits/stdc++.h>
//#include<fstream>
using namespace std;
int main()
{

    ofstream l;
    l.open("11805.txt");
    int n,a,b,c,d,e,f,g,i,x=1;
    while(cin>>n)
    {
    x=1;
    while(n>0)
    {
        cin>>a>>b>>c;
        for(i=b; i<a; i++)
        {
            c--;
        }
        //cout<<c;

        while(c>0)
        {
        for(i=1; i<=a; i++)
        {
            c--;
            if(c==0)
            {
                break;
            }
           }
        }

        l<<"Case "<<x<<": "<<i<<endl;
        n--;
        x++;
      }
    }
    return 0;
}

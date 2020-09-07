#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,e,f,g,h,x,y,i,j;
    while(cin>>a>>b>>c>>d)
    {
        if(a==0 && b==0 && c==0 && d==0){break;}
        if(c>a)
        {
            e=(c-a)*60+(d-b);
        }
        else if(c<a)
        {
            e=(1440-((a*60)+b))+((c*60)+d);
        }
        else if(a==c && b<=d)
        {
            e=d-b;
        }
        else
        {
            e=(1440-(b-d));
        }
          cout<<e<<endl;
    }
    return 0;
}
//1 5 3 5
//23 59 0 34
//21 33 21 10
//120
//35
//1417

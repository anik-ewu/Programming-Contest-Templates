#include<iostream>
using namespace std;
int main()
{
    int x,y;
    double a,b,c,d,l,e,f,j,k;
    while(cin>>a>>b>>c>>d)
    {
        if(a==0 && b==0 && c==0 && d==0){break;}
        x=1;
        k=b;
        l=(b/100.0)*d;
        while(1)
        {

           if(b>a){cout<<"success on day "<<x<<endl;break;}
           b=b-c;
           if(b<0){cout<<"failure on day "<<x<<endl;break;}
           k=k-l;
           b=b+k;
           x++;
        }
    }
    return 0;
}
//56 3 1 5

#include<iostream>
using namespace std;
int main()
{
    long long int a,b,c,d,e=1,x,f,g;
    while(cin>>a>>b)
    {
        if(a==-1 && b==-1){break;}
        f=a;
        g=b;
        x=1;
        while(1)
        {
            if(a==1){break;}

            if(a%2==0){a=a/2;}
            else
            {
                a=(a*3)+1;
            }
            if(a>b){break;}
            x++;

        }
        cout<<"Case "<<e<<": A = "<<f<<", limit = "<<g<<", number of terms = "<<x<<endl;
        e++;
    }
    return 0;
}
//Case 1: A = 3, limit = 100, number of terms = 8

#include<iostream>
using namespace std;
int main()
{
    int a,b,c,n;
    while(cin>>n)
    {
        a=n;
        c=0;
        while(1)
        {
            if(n<2){break;}
            if(n%3>1){
                c=1;
                n++;}
            n=n/3;
            a=a+n;
           // n=n-c;
            c=0;
        }
        cout<<a<<endl;
    }
    return 0;
}

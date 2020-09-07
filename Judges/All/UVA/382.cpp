#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,e,f,n,i,x;
    n=1;
    cout<<"PERFECTION OUTPUT"<<endl;
    while(n<=100)
    {

        cin>>a;
        b=0;
        if(a==0){break;}
        for(i=1; i<a; i++){
        if(a%i==0){b=b+i;}}
        if(b==a){printf("%5d  PERFECT\n",a);}
        else if(b<a){printf("%5d  DEFICIENT\n",a);}
        else if(b>a){printf("%5d  ABUNDANT\n",a);}
        n++;
    }
    cout<<"END OF OUTPUT"<<endl;
    return 0;


}
//ABUNDANT
//22 DEFICIENT
//496 PERFECT

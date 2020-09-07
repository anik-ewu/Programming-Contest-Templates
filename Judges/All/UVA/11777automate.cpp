#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,e[10],n,i,j,f,g=0,y,r=1;
    cin>>n;
    r=1;

    while(n>0)
    {
        cin>>a>>b>>c>>d;
        y=0;
        for(i=1; i<=3; i++)
        {
            cin>>e[i];
        }
        for(i=1; i<=3; i++){
        for(j=i+1; j<=3; j++)
        {
            if(e[i]>e[j])
            {
                y=e[i];
                e[i]=e[j];
                e[j]=y;
            }
        }
        }

        f=e[2]+e[3];
        if(f!=0){f=f/2;}
        g=a+b+c+d+f;

        if(g>=90){cout<<"Case "<<r<<": "<<"A"<<endl;r++;}
        else if(g<90 && g>=80){cout<<"Case "<<r<<": "<<"B"<<endl;r++;}
        else if(g<80 && g>=70){cout<<"Case "<<r<<": "<<"C"<<endl;r++;}
        else if(g<70 && g>=60){cout<<"Case "<<r<<": "<<"D"<<endl;r++;}
        else if(g<60){cout<<"Case "<<r<<": "<<"F"<<endl;r++;}
        n--;
    }
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int  a[5],i,j,x,y,n,p,q,r;
    cin>>n;
    y=1;
    while(n>0)
    {
        for(j=1; j<=3; j++){
            cin>>a[j];}
        for(i=1; i<=3; i++)
            for(j=i+1; j<=3; j++)
        {
            if(a[i]<a[j])
            {
                x=a[i];
                a[i]=a[j];
                a[j]=x;
            }
        }
        p=a[1];q=a[2];r=a[3];
        if(p<=0 || q<=0 || r<=0){cout<<"Case "<<y<<": Invalid"<<endl;}
        else if(q+r<=p){cout<<"Case "<<y<<": Invalid"<<endl;}
        else if(p+r<=q){cout<<"Case "<<y<<": Invalid"<<endl;}
        else if(p+q<=p){cout<<"Case "<<y<<": Invalid"<<endl;}
        else
        {
            if(p==q && q==r){cout<<"Case "<<y<<": Equilateral"<<endl;}
            else if(p==q || p==r || q==r){cout<<"Case "<<y<<": Isosceles"<<endl;}
            else{cout<<"Case "<<y<<": Scalene"<<endl;}


        }

        n--;
        y++;

    }
    return 0;
}
//Case 1: Invalid
//Case 2: Equilateral
//Case 3: Isosceles
//Case 4: Scalene
//1 2 5 1 1 1 4 4 2 3 4 5

#include<iostream>
using namespace std;

bool isLeapYear(int year)
{
    if (year % 400 == 0) return true;
    else if(year % 100 == 0) return false;
    else if(year % 4 == 0) return true;
    else return false;
}
int main()
{
    long long int n,a,b,c,d,i,j;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>a>>b>>c>>d;
        int co=0;
        if(a==29)
        {
            for(j=c+1; j<=d; j++)
            {
                if(isLeapYear(j))
                    co++;
            }
        }
        else
        {
            co=d-c;
        }
        cout<<"Case "<<i<<": "<<co<<endl;
    }
    return 0;
}

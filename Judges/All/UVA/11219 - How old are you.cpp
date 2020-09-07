#include<bits/stdc++.h>
using namespace std;


int main()
{
    int dd,mm,yy;
    int dd2,mm2,yy2;

    char f;
    int n,m,i,j,k;
    bool invalid;

    cin>>n;
    for(i=1; i<=n; i++)
    {

        cin>>dd>>f>>mm>>f>>yy;
        cin>>dd2>>f>>mm2>>f>>yy2;

        invalid=false;
        ///the calculated age is impossible
        if(yy<yy2 || (yy==yy2 and mm<mm2) || (yy==yy2 and mm==mm2 and dd<dd2))
        {
            invalid=true;
        }
        if(!invalid)
        {
            if(mm<mm2 || (mm==mm2 and dd<dd2))
                yy--;
            if(yy-yy2>130)
                cout<<"Case #"<<i<<": Check birth date"<<endl;
            else
                cout<<"Case #"<<i<<": "<<yy-yy2<<endl;

        }
        else
            cout<<"Case #"<<i<<": Invalid birth date"<<endl;

    }
    return 0;
}

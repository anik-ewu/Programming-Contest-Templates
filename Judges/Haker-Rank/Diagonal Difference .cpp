#include<bits/stdc++.h>
using namespace std;

int grid[200][200];

int main()
{
    int i,j,k,a,b,x=0,y=0,n;
    int mark;
    cin>>n;
    mark=n;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            cin>>a;
            if(i==j)
                x+=a;
            if(j==mark)
                y+=a;

        }
        mark--;
    }
    mark=abs(x-y);
    cout<<mark<<endl;
    return 0;
}

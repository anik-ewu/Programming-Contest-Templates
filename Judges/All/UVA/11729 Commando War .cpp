#include<bits/stdc++.h>
using namespace std;

vector < pair < int , int > > vp;

int find_time(int n)
{
    int cal,i,j,x,y,sum=0;

    for(i=0; i<n; i++)
    {
        x=vp[i].first*-1;
        y=vp[i].second;
        swap(x,y);
        if(!i)
        {
            cal=y;
            sum+=(x+y);
        }
        else
        {
            if(cal>x)
            {
                cal-=x;
                if(y>=cal)
                {
                    sum+=(y-cal);
                    cal+=(y-cal);
                }
            }
            else
            {
                sum+=(x-cal);
                sum+=y;
                cal=y;
            }
        }
    }
    return sum;
}



int main()
{
    int cs=1,i,j,a,b,n,m;

    while(cin>>n)
    {
        if(n==0)
            break;

        for(i=1; i<=n; i++)
        {
            cin>>a>>b;
            vp.push_back(make_pair(-b,a));
        }
        sort(vp.begin(),vp.end());

        int ans=find_time(n);

        cout<<"Case "<<cs++<<": "<<ans<<endl;
        vp.clear();

    }

    return 0;
}

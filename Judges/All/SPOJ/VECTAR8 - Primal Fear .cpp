#include<bits/stdc++.h>
using namespace std;
#define S 1005002
bool mark[S+7];
int arr[S+7];
vector < int > v,nn;

bool nozero(int n)
{
    nn.clear();

    int x,y,z;

    while(n)
    {
        x=n%10;
        if(x==0)
            return false;
        nn.push_back(x);

        n/=10;
    }
    x=0;
    ///cout<<nn.size()<<endl;
    for(int i=nn.size()-1; i>=0; i--)
    {
        x=0;
        for(int j=i; j>=0; j--)
        {
            x+=nn[j];
            x*=10;
        }
        x/=10;
        if(mark[x]==false)
            return false;
    }
    ///nn.clear();

    return true;
}


void  seive()
{
    int i,j,k,x,num;

    for(int i=1; i<S; i++)
        mark[i]=true;

    mark[1]=false;
    for(i=4; i<=S; i+=2)
        mark[i]=false;

    for(i=3; i*i<=S; i+=2)
    {
        if(mark[i]==true)
        {
            for(j=i*i; j<S; j+=i+i)
                mark[j]=false;
        }
    }
    v.push_back(2);
    arr[1]=0;
    arr[2]=1;
    x=1;
    for(i=3; i<=1000005; i++)
    {
        if(mark[i]==true)
        {
            if(nozero(i))
                x++;
        }
        arr[i]=x;
    }
}

int main()
{
    seive();
    int n,i,j,ind;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&ind);
        printf("%d\n",arr[ind]);
    }
    return 0;
}

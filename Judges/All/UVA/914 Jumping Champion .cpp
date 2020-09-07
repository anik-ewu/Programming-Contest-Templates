#include<bits/stdc++.h>
using namespace std;

#define sz 1000600
int arr[1000006];
bool mark[sz+2];
vector < int > prime,ans,unique_number;

void seive()
{
    int i,j;
    for(i=1; i<sz; i++)
        mark[i]=true;
    for(i=4; i<sz; i+=2)
        mark[i]=false;


    mark[1]=false;
    mark[2]=true;
    for(i=3; i*i<sz; i++)
    {
        if(mark[i])
        {
            for(j=i*i; j<sz; j+=(i*2))
                mark[j]=false;
        }
    }
    prime.push_back(2);
    for(i=3; i<sz; i+=2)
        if(mark[i])
            prime.push_back(i);
}

void jumping_champ(int l, int r)
{

    int a,b,x,y,i,j;
    while(mark[l]==false)
        l++;
    while(mark[r]==false)
        r--;

    for(i=l+1; i<=r; i++)
    {
        if(mark[i]==true)
        {
            a=i-l;
            l=i;
            arr[a]++;
            if(arr[a]==1)
                ans.push_back(a);
        }
    }

    bool flag=false;
    int champ=0,count=0;

    for(i=0; i<ans.size(); i++)
    {
        if(arr[ans[i]]>count)
        {
            count=arr[ans[i]];
            champ=ans[i];
        }
    }

    int danger=0;
    for(i=0; i<ans.size(); i++)
    {
        if(arr[ans[i]]==count)
        {
            danger++;
            if(danger>1)
                break;
        }
    }
    if(danger>1 || ans.size()==0)
        flag=true;

    if(flag)
    {
        printf("No jumping champion\n");
    }
    else
    {
        printf("The jumping champion is %d\n",champ);
    }

    ///clear
    for(i=0; i<ans.size(); i++)
        arr[ans[i]]=0;
    ans.clear();
}

int main()
{

    seive();
    int n,i,j,l,r;
    scanf("%d",&n);
    for(j=1; j<=n; j++)
    {
        scanf("%d%d",&l,&r);
        jumping_champ(l,r);
    }

    return 0;
}

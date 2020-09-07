#include<bits/stdc++.h>
using namespace std;

#define sz
int arr[2000];
bool mark[2000];
vector < int > prime;

void seive()
{
    int i,j;
    for(i=1; i<1500; i++)
        mark[i]=true;
    for(i=4; i<1500; i+=2)
        mark[i]=false;

    for(i=3; i*i<1500; i++)
    {
        if(mark[i])
        {
            for(j=i*i; j<1500; j+=(i*2))
                mark[j]=false;
        }
    }
    prime.push_back(2);
    for(i=3; i<1500; i+=2)
        if(mark[i])
            prime.push_back(i);
}

int main()
{
    seive();
    int n,i,j,x,y;

    while(cin>>n)
    {
        if(n==0)
            break;

        for(i=2; i<=n; i++)
            arr[i]=0;

        for(i=0; prime[i]<=n; i++)
        {
            int num=prime[i];
            while(n>=num)
            {
                arr[prime[i]]+=(n/num);
                num*=prime[i];
            }

        }

        printf("%3d! =",n);
        x=0;
        y=1;
        for(i=2; i<=n; i++)
        {
            if(arr[i] and y )
                printf("%3d",arr[i]),x++;
            else if(arr[i] and x==0)
                printf("%9d",arr[i]),x++;
            else if(arr[i])
                printf("%3d",arr[i]),x++;

            if(x==15)
            {
                cout<<endl;
                x=0;
                y=0;
            }

        }
        if(x)
            cout<<endl;
    }

    return 0;
}

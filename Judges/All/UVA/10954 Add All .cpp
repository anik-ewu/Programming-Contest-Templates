#include<bits/stdc++.h>
using namespace std;

int main()
{

    priority_queue < int > pq;
    int i,j,k,n,m,a,b,sum;
    while(cin>>n)
    {
        if(n==0)
            break;
        sum=0;
        for(i=0; i<n; i++)
        {
            cin>>a;
            pq.push(-a);
        }
        while(pq.size()>1)
        {
            a=pq.top()*-1;
            pq.pop();
            b=pq.top()*-1;
            pq.pop();
            sum+=(a+b);
            pq.push((a+b)*-1);
        }
        cout<<sum<<endl;
        pq.pop();
    }
    return 0;
}

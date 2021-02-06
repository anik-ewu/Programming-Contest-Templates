#include<bits/stdc++.h>
using namespace std;
vector < int > cost(10001, -1);
void bfs(int n, int m)
{
    queue< int > q;
    int top;
    q.push(n);
    cost[n]=0;
    while(!q.empty())
    {
        top=q.front();
        if(top==m)
        {
            return ;
        }
        q.pop();

        int x=top*2;
        if(x<=10000 && cost[x]==-1)
        {
            cost[x]=cost[top]+1;
            q.push(x);
        }
        if(top>1 && cost[top-1]==-1)
        {
            cost[top-1]=cost[top]+1;
            q.push(top-1);

        }

    }
}
int main()
{
    int n,m;

    cin>>n>>m;
    if(m<=n)
        cout<<n-m<<endl;
    else
    {

        bfs(n,m);
        cout<<cost[m]<<endl;
    }
    return 0;
}

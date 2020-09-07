#include<bits/stdc++.h>
using namespace std;

int main()
{
    set < int > st;
    int i,j,k,n,m,a,x,y,ans=0;
    while(cin>>n>>m)
    {
        if(n==0)
            break;
        while(n--)
        {
            cin>>a;
            st.insert(a);
        }
        ans=0;
        while(m--)
        {
            cin>>a;
            x=st.size();
            st.insert(a);
            y=st.size();
            if(x==y)
                ans++;
        }
        st.clear();
        cout<<ans<<endl;

    }

    return 0;
}

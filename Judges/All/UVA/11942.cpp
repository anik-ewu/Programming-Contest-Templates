#include<iostream>
using namespace std;
int main()
{
    int n,a,b,c,i,j,k,x,y;
    cin>>n;
    cout<<"Lumberjacks:"<<endl;
    while(n>0)
    {

        x=0;
        y=0;
        for(i=1; i<=10; i++)
        {
            cin>>a;
            if(i==1){c=a;}
            if(i!=1)
            {
                if(a>c){x++;c=a;}
                if(a<c){y++;c=a;}
            }
        }
        if(x==0 || y==0){cout<<"Ordered"<<endl;}
        else{cout<<"Unordered"<<endl;}
        n--;
    }
    return 0;
}

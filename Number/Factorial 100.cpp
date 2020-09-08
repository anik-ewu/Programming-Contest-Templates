#include<iostream>
using namespace std;
int  arry[10000000];

void factorial(int arry[],int m, int f_num)
{

    int x,temp=0,i=0;
    while(f_num>1)
    {
        i=0;
        do
        {
            x=arry[i]*f_num+temp;
            arry[i]=x%10;
            temp=x/10;
            ++i;
        }
        while(temp!=0 || i<=m);
        m=--i;
        --f_num;

    }
    while(m>=0)
    {
        cout<<arry[m];
        --m;
    }
    cout<<endl;
}

int main()
{
    int num,f_num,i,sum,x,y;
    while(cin>>num)
    {
        cout<<num<<'!'<<endl;
        if(num<=5)
        {
            sum=1;
            while(num>1)
            {
                sum*=num;
                num--;
            }
            cout<<sum<<endl;
        }
        else
        {
            f_num=num-1;
            i=0;
            while(1)
            {
                if(num==0)
                    break;
                arry[i++]=num%10;
                num/=10;
            }
            factorial(arry, i, f_num);
            for(i=0; i<=7000; i++)
                arry[i]=0;
        }

    }
    return 0;
}

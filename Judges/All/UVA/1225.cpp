#include<iostream>
using namespace std;
int main()
{
    int a,b,c,n,i,j,x,y,a1,a2,a3,a4,a5,a6,a7,a8,a9,a0;
    cin>>n;
    while(n>0)
    {
        cin>>a;
        a1=a2=a3=a4=a5=a6=a7=a8=a9=a0=0;
        for(i=1; i<=a; i++){
        x=i;
        while(1)
        {
            b=x%10;
            x=x/10;
            if(b==0){a0++;}
            if(b==1){a1++;}
            if(b==2){a2++;}
            if(b==3){a3++;}
            if(b==4){a4++;}
            if(b==5){a5++;}
            if(b==6){a6++;}
            if(b==7){a7++;}
            if(b==8){a8++;}
            if(b==9){a9++;}
            if(x==0){break;}
        }
        }
        cout<<a0<<' '<<a1<<' '<<a2<<' '<<a3<<' '<<a4<<' '<<a5<<' '<<a6<<' '<<a7<<' '<<a8<<' '<<a9<<endl;

        n--;
        }
        return 0;
}

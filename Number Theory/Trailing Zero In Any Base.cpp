#include<bits/stdc++.h>
using namespace std;
#define S 1000000
int mark[S+6],prime[S];
int sieve(){
    int x,y;
    memset(mark,0,sizeof(mark))
    mark[0]=mark[1]=1;
    for(x=4; x<S; x=x+2)
        mark[x]=1;
    for(x=3; x*x<=S; x=x+2){
        if(mark[x]==0){
            for(y=x*x; y<=S; y=y+x+x)
                mark[y]=1;
        }
    }
    y=0;
    for(x=2; x<S; x++)
        if(mark[x]==0)
            prime[y++]=x;

}
int factorial_trailing_zero(int num,int base){
    int ans=-1;
    int y=0;
    while(prime[y]<=base){
        int count=0;
        if(base%prime[y]==0){
            while(base%prime[y]==0){
                base=base/prime[y];
                count++;
            }
            int d=prime[y];
            int e=0;
            while(num>=d){
                e=e+(num/d);
                d=d*prime[y];
            }
            int temp;
            temp=e/count;
            if(temp<ans||ans==-1)
                ans=temp;
        }
        y++;
    }
    return ans;
}
int main(){
    sieve();
    int a,b,c,x,y,z,num,base;
    while(cin>>num>>base){
        cout<<factorial_trailing_zero(num,base)<<endl;
    }
    return 0;
}

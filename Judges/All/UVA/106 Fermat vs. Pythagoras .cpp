#include<bits/stdc++.h>
using namespace std;

map < int , int > mp;
long long int arr[1000006];

void cal(int n )
{
    long long int ans=0 , cn=0,i,j,k;
    for(i=1; i<=n; i++)
        arr[i]=0;
    for(i=1; i*i<=n; i++){
        for(j=i+1; j*j<=n; j+=2){
            if(__gcd(i,j)==1){
                int x=j*j-i*i;
                int y=2*i*j;
                int z=j*j+i*i;

                if(z>n)break;

                int a=x,b=y,c=z;

                while(c<=n){
                    arr[a]= arr[b] = arr[c] =1;
                    a+=x;
                    b+=y;
                    c+=z;
                }
                cn++;
            }
        }
    }

    ans=n;
    for(i=1; i<=n; i++)
        ans-=arr[i];

    cout<<cn<<' '<<ans<<endl;
}
int main()
{
    int n;

    while(cin>>n){
    cal(n);

   }

    return 0;
}

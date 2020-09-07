#include<bits/stdc++.h>
using namespace std ;

#define mod 131071

int main(){

    char s;
    long long int ans =0;

    while(s=getchar()){
          if(s==-1)break; /// contol z

         if(s=='0' || s=='1'){
            ans=(ans<<1)+s-'0';
            if(ans>=131071)
                ans=ans %mod;
         }
         if(s=='#'){
            puts(ans ? "NO" : "YES");
            ans=0;
         }
         cout<<ans<<endl;
    }

    return 0;
}

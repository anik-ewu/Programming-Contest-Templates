///Date: 25-8-2020
///Approach: Sos DP

#include<bits/stdc++.h>
using namespace std;

const int K=24, N=1<<24;

int dp[N];

int process(string s){
    int mask=0;
    for(int i=0;i<3;i++){
        int x=int (s[i]-'a');
        mask=mask|(1<<x);
    }
    return mask;
}

int main(){

    int n;
    string s;

    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>s;
        dp[process(s)]++;
    }

    for(int i=0; i<K; i++){
        for(int mask=0; mask<N; mask++){
            if(mask & (1<<i)){
                dp[mask]+=dp[mask ^(1<<i)];
            }
        }
    }

    long long ans=0;
    for(int i=0; i<N; i++){
        long long x=(n-dp[i]);
        ans^=(x*x);///xor of the squared numbers
    }
    cout<<ans<<endl;

    return 0;
}

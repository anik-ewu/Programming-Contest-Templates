///20
#include<bits/stdc++.h>
using namespace std;

const int N = 22, M = 1e9+7;
long long a[N];
long long invfac[N];

long long power(long long a, long long p) {
    if (p==0)   return 1;
    long long ans = power(a, p/2);
    ans = (ans * ans)%M;
    if (p%2)    ans = (ans * a)%M;
    return ans;
}

int f(int n, long long sum) {
    if (sum<0)  return 0;
    sum = ((sum+n-1)%M + M)%M;
    long long ans = 1;
    for (int i=0; i<n-1; i++)
        ans = (ans*(sum-i+M))%M;
    ans = (ans*invfac[n-1])%M;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    invfac[0] = 1;
    for (int i=1; i<N; i++)
        invfac[i] = (1LL*invfac[i-1]*power(i, M-2))%M;

    int n;
    long long x;
    cin>>n>>x;

    for (int i=0; i<n; i++) cin>>a[i];
    long long ans = 0;

    for (int mask=0; mask < (1<<n); mask++) {
        long long sum = x;
        for (int i=0; i<n; i++)
            if (mask & (1<<i))
                sum -= a[i]+1;
        cout<<sum<<endl;
        if (__builtin_popcount(mask)%2)      ans = (ans + M - f(n, sum))%M;
        else                                 ans = (ans + f(n, sum))%M;
    }
    cout<<ans<<endl;
}

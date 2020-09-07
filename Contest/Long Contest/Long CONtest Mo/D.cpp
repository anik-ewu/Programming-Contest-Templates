#include<bits/stdc++.h>
using namespace std;
#define sz 1000006
#define ll long long
ll int sum=0;
ll int len,fre[sz];
ll int arr[sz],ans[sz];
struct st{
    ll int l, r, idx;
}q[200050];
bool cmp(st &a, st &b){
    if(a.l/len!=b.l/len)
        return a.l/len<b.l/len;
    return a.r<b.r;
}
void del(int pos){
    ll a=arr[pos];
    sum-=(fre[a]*fre[a])*a;
    fre[a]--;
    sum+=(fre[a]*fre[a])*a;
}
void add(int pos){
    ll a=arr[pos];
    sum-=(fre[a]*fre[a])*a;
    fre[a]++;
    sum+=(fre[a]*fre[a])*a;
}

int main(){

    ll int n,m,i,j,k;
    scanf("%lld%lld",&n,&m);
    len=500;
    for(i=0; i<n; i++){
        scanf("%lld",&arr[i]);
    }
    for(i=1; i<=m; i++){
        scanf("%lld%lld",&q[i].l,&q[i].r);
        q[i].idx=i;
    }
    sort(q+1,q+m+1,cmp);
    int currentL=0;
    int currentR=0;
    for(i=1; i<=m; i++){
        ll int l=q[i].l-1;
        ll int r=q[i].r-1;
        while(currentL<l){
            del(currentL);
            currentL++;
        }
        while(currentL>l){
            add(currentL-1);
            currentL--;
        }
        while(currentR<=r){
            add(currentR);
            currentR++;
        }
        while(currentR>r+1){
            del(currentR-1);
            currentR--;
        }
        ans[q[i].idx]=sum;
    }
    for(i=1; i<=m; i++){
        printf("%lld\n",ans[i]);
    }
    return 0;
}

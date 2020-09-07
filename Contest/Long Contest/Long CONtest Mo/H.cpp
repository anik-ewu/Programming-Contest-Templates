#include<bits/stdc++.h>
using namespace std;
#define sz 100105
typedef long long int ll;
ll len,k;
ll ans[sz],result;
ll arr[sz],cnt[(1<<21)];///max XOR value can be up to 1<<20
struct st{
    int l,r,id;
}q[sz];
bool cmp(st &a, st &b){
    if(a.l/len!=b.l/len)
        return  a.l/len<b.l/len;
    return a.r<b.r;
}

void add(ll v) {
    result += cnt[v ^ k];
    cnt[v]++;
}
void del(ll v) {
    cnt[v]--;
    result -= cnt[v ^ k];
}

int main(){
    ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);

    ll n,m,i,l,r;
    cin>>n>>m>>k;
    len=sqrt(n)+1;
    for(i=1; i<=n; i++){
        cin>>arr[i];
        arr[i]=arr[i]^arr[i-1];
    }
    for(i=1; i<=m; i++){
        cin>>q[i].l>>q[i].r;
        q[i].id=i;
    }
    sort(q+1,q+m+1,cmp);
    int currentL=0;
    int currentR=-1;
    for(i=1; i<=m; i++){
            int l=q[i].l-1;
            int r=q[i].r;
            while(currentL>l){
                currentL--;
                add(arr[currentL]);
            }
            while(currentR<r){
                currentR++;
                add(arr[currentR]);
            }
            while(currentL<l){
                del(arr[currentL]);
                currentL++;
            }
            while(currentR>r){
                del(arr[currentR]);
                currentR--;
            }
        ans[q[i].id]=result;
    }
    for(i=1; i<=m; i++){
        cout<<ans[i]<<"\n";
    }

    return 0;
}

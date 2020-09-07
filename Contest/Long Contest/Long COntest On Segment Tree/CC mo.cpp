#include<bits/stdc++.h>
using namespace std;
#define sz 50050
int len;
int mrk[3];
int arr[sz];
int ans[sz];
map < int , int > mp;
struct st{
    int l, r,id;
}q[sz];

bool cmp(st a, st b){
    if(a.l/len!=b.l/len)
        return a.l<b.l;
    return a.r<b.r;
}

void add(int idx){
    mrk[arr[idx]]++;
}
void del(int idx){
    mrk[arr[idx]]--;
}

int main(){

    int n,i,j,m;
    cin>>n>>m;
    len=sqrt(n)+1;
    for(i=0; i<n; i++){
        cin>>arr[i];
        if(i)arr[i]+=arr[i-1];
    }
    for(i=1; i<=m; i++){
        cin>>q[i].l>>q[i].r;q[i].l--;q[i].r--;
        q[i].id=i;
    }
    sort(q,q+n,cmp);
    int L=0,  R=-1;
    for(i=1; i<=m; i++){
        while(L>q[i].l)add(--L);
        while(R<q[i].r)add(++R);
        while(L<q[i].l)del(L++);
        while(R>q[i].r)del(R--);
        ans[q[i].id]=mx;
    }
    for(i=1; i<=m; i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}

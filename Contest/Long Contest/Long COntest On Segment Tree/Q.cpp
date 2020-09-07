#include<bits/stdc++.h>
using namespace std;
#define sz 100005
int len,mx;
int arr[sz];
int ans[sz];
int fre[sz],ffre[sz];
struct st{
    int l,r,id;
}q[sz];

bool cmp(st &a, st &b){
    if(a.l/len!=b.l/len)
        return a.l<b.l;
    return a.r<b.r;
}
void add(int pos){
    fre[arr[pos]]++;
    ffre[fre[arr[pos]]]++;
    mx=max(mx,fre[arr[pos]]);
}
void del(int pos){
    int a=arr[pos];
    int b=fre[a];
    fre[a]--;
    ffre[b]--;
    if(ffre[b]==0){
        mx=fre[a];
    }
}


int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);

    int cs=1,t,n,i,j,m,c;
    //cin>>t;
    scanf("%d",&t);
    while(t--){
        //cin>>n>>c>>m;
        scanf("%d%d%d",&n,&c,&m);
        len=sqrt(n)+1;
        memset(fre,0,sizeof(fre));
        memset(ffre,0,sizeof(ffre));
        for(i=0; i<n; i++)cin>>arr[i];
        for(i=0; i<m; i++){
        scanf("%d%d",&q[i].l,&q[i].r);
            q[i].l--;q[i].r--;
            q[i].id=i;
        }
        sort(q,q+m,cmp);
        int l=0,  r=-1;
        mx=0;
        for(i=0; i<m; i++){
            while(l>q[i].l)add(--l);
            while(r<q[i].r)add(++r);
            while(l<q[i].l)del(l++);
            while(r>q[i].r)del(r--);
            ans[q[i].id]=mx;
        }
        ///cout<<"Case "<<cs++<<":"<<endl;
        printf("Case %d:\n",cs++);
        for(i=0; i<m; i++){
            ///cout<<ans[i]<<endl;
            printf("%d\n",ans[i]);
        }
    }


    return 0;
}

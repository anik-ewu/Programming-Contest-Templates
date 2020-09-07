#include<bits/stdc++.h>
using namespace std;
#define sz 200005
int len;
int arr[sz],brr[sz];
vector< int> block[500];

int queryBig(int l, int r, int k){
    int cnt=0;
    int cl=l/len;
    int cr=r/len;
    if(cl==cr){
         for(int i=l; i<=r; i++){
            if(arr[i]>k  and arr[i])cnt++;
         }
    }
    else{
        for(int i=l, end=(cl+1)*len-1; i<=end; i++){
            if(arr[i]>k and arr[i])cnt++;
        }
        for(int i=cl+1; i<=cr-1; i++){
            int idx=upper_bound(block[i].begin(),block[i].end(),k)-block[i].begin();
            cnt+=(block[i].size()-idx);
        }
        for(int i=cr*len; i<=r; i++){
            if(arr[i]>k  and arr[i])cnt++;
        }
    }
    return cnt;
}

int querySmall(int l, int r, int k){
    int cnt=0;
    int cl=l/len;
    int cr=r/len;
    if(cl==cr){
         for(int i=l; i<=r; i++){
            if(arr[i]<k and arr[i])cnt++;
         }
    }
    else{
        for(int i=l, end=(cl+1)*len-1; i<=end; i++){
            if(arr[i]<k and arr[i])cnt++;
        }
        for(int i=cl+1; i<=cr-1; i++){
            int num=lower_bound(block[i].begin(),block[i].end(),k)-block[i].begin();
            cnt+=num;
        }
        for(int i=cr*len; i<=r; i++){
            if(arr[i]<k  and arr[i])cnt++;
        }
    }
    return cnt;
}

int main(){

    ///ios_base::sync_with_stdio(false);
    ///freopen("out.txt","w",stdout);
    int n,i,m;
    while(scanf("%d%d",&n,&m)==2){
        len=sqrt(n)+1;
        for(i=0; i<=len+1; i++)block[i].clear();
        for(i=0; i<n; i++){
            scanf("%d",&arr[i]);
            brr[arr[i]]=i;
            block[i/len].push_back(arr[i]);
        }
        for(i=0; i<len; i++){
            if(block[i].size())
                sort(block[i].begin(),block[i].end());
        }
        int pos;
        long long int inv=0;
        for(i=1; i<=n; i++){
            inv+=(long long)queryBig(0,i-1,arr[i-1]);
        }
        int val;
        while(m--){
            scanf("%d",&val);
            printf("%lld\n",inv);

            int idx=brr[val];
            int blk=idx/len;
            for(i=0; i<block[blk].size(); i++){
                if(block[blk][i]==val){
                    block[blk].erase(block[blk].begin()+i);break;
                }
            }
            arr[idx]=0;
            int a=queryBig(0,idx-1,val);
            int b=querySmall(idx+1,n-1,val);
            inv-=(a+b);
        }
    }
    return 0;

}

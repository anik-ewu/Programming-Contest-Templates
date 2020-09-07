#include<bits/stdc++.h>
using namespace std;

#define sz 30005
int len;
int arr[sz];
vector< int> block[200];

int query(int l, int r, int k){
    int cnt=0;
    int cl=l/len;
    int cr=r/len;
    if(cl==cr){
         for(int i=l; i<=r; i++){
            if(arr[i]>k)cnt++;
         }
    }
    else{
        for(int i=l, end=(cl+1)*len-1; i<=end; i++){
            if(arr[i]>k)cnt++;
        }
        for(int i=cl+1; i<=cr-1; i++){
            int idx=upper_bound(block[i].begin(),block[i].end(),k)-block[i].begin();
            cnt+=(block[i].size()-idx);
        }
        for(int i=cr*len; i<=r; i++){
            if(arr[i]>k)cnt++;
        }
    }
    return cnt;
}

int main(){

    ///ios_base::sync_with_stdio(false);cout.tie(false);cin.tie(false);
    int n,i,m;
    scanf("%d",&n);
    len=sqrt(n)+1;
    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
        block[i/len].push_back(arr[i]);
    }
    ///process
    for(i=0; i<len; i++){
        if(block[i].size())
            sort(block[i].begin(),block[i].end());
    }
    scanf("%d",&m);
    int blk,type,l,r,k,val,pos;
    while(m--){
        scanf("%d",&type);
        if(type){
            scanf("%d%d%d",&l,&r,&k);
            l--;r--;
            printf("%d\n",query(l,r,k));
        }
        else{
            scanf("%d%d",&pos,&val);
            pos--;
            arr[pos]=val;
            blk=pos/len;
            l=blk*len;
            r=l+len;
            block[blk].clear();
            for(i=l; i<r; i++)
                block[blk].push_back(arr[i]);
            sort(block[blk].begin(),block[blk].end());
        }
    }
    return 0;

}

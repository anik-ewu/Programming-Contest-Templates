///UVA       :11990 Dynamic Inversion
///Approach  :Square Root Decomposition
///Complexity:TLE(3)

#include<bits/stdc++.h>
using namespace std;

int len;
int blk;
vector < int > arr(200005);
vector < int > pos(200005);
vector < int > block[500];
int find_total(int n){

    int cnt=0;
    for(int j=0; j<n; j++){
        int l=j+1;
        int cl=l/len;
        int cr=n/len;
        if(cl==cr){
            for(int i=l; i<n; i++){
                if(arr[i]<arr[j])cnt++;
            }
        }
        else{
            for(int i=l, end=(cl+1)*len-1;i<=end; ++i){
                if(arr[i]<arr[j])cnt++;
            }
            for(int i=cl+1; i<=cr-1; i++){
                int idx=lower_bound(block[i].begin(),block[i].end(),arr[j])-block[i].begin();
                cnt+=idx;
            }
            for(int i=cr*len; i<n; i++){
                if(arr[i]<arr[j])cnt++;
            }
        }
    }
    return cnt;
}

int left(int l, int r, int v){

    int cnt=0;
    int cl=l/len;
    int cr=r/len;
    if(cl==cr){
        for(int i=l; i<r; i++){
            if(arr[i]>v)cnt++;
        }
    }
    else{
        for(int i=l, end=(cl+1)*len-1;i<=end; ++i){
            if(arr[i]>v)cnt++;
        }
        for(int i=cl+1; i<=cr-1; i++){
            int idx=lower_bound(block[i].begin(),block[i].end(),v)-block[i].begin();
            cnt+=(block[i].size()-idx);
        }
        for(int i=cr*len; i<r; i++){
            if(arr[i]>v)cnt++;
        }
    }
    return cnt;
}
int right(int l, int r, int v){

    int cnt=0;
    int cl=l/len;
    int cr=r/len;
    if(cl==cr){
        for(int i=l; i<r; i++){
            if(arr[i]<v && arr[i]>0)cnt++;
        }
    }
    else{
        for(int i=l, end=(cl+1)*len-1;i<=end; ++i){
            if(arr[i]<v && arr[i]>0)cnt++;
        }
        for(int i=cl+1; i<=cr-1; i++){
            int idx=lower_bound(block[i].begin(),block[i].end(),v)-block[i].begin();
            cnt+=idx;
        }
        for(int i=cr*len; i<r; i++){
            if(arr[i]<v && arr[i]>0)cnt++;
        }
    }
    return cnt;
}

int main(){

    ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
    freopen("out.txt","w",stdout);

    int n,i,j,a,b,c,k,q,m,l;
    while(cin>>n>>m){
        len=sqrt(n)+1;///block length
        blk=(n/len)+(n%len?1:0);///number of blocks
        arr.clear();
        for(i=0; i<n; i++){
            cin>>arr[i];
            pos[arr[i]]=i;
            block[i/len].push_back(arr[i]);
            arr.push_back(arr[i]);
        }
        ///process block
        for(i=0; i<blk; i++){
            if(block[i].size())
                sort(block[i].begin(),block[i].end());
        }
        ///total inversion
        int total=find_total(n);

        while(m--){
            cin>>a;
            int idx=pos[a];
            arr[idx]=-1;
            int x=(idx/len);
            int y=x*len;
            for(j=y; j<y+len; j++);{
                if(arr[i]>0)
                    block[x].push_back(arr[j]);
            }
            cout<<total<<endl;
            if(block[x].size())sort(block[x].begin(),block[x].end());
            x=left(0,idx,a);
            y=right(idx,n,a);
            //cout<<x<<' '<<y<<endl;
            //total-=(x+y);

        }
        ///clear
        for(i=0; i<blk; i++)
            block[i].clear();
    }

    return 0;
}

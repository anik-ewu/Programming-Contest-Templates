///Approach : Binary Search

#include<bits/stdc++.h>
using namespace std;
vector < int > v;

bool check(int m, int mid){

    int i,sum=0,count=0;
    for(i=0; i<v.size(); i++){
        if(v[i]>mid || m==0)return false;

        if(sum+v[i]<=mid){
            sum+=v[i];
        }
        else{
            m--;
            sum=v[i];
        }
    }
    if(sum>0 && m==0)return false;
    return true;
}

int bisection(int m,int sum){

    int low=1;
    int high=sum;
    while(high-low>2){
        int mid=low+(high-low)/2;

        if(check(m,mid)){
            high=mid;
        }
        else
            low=mid+1;
    }

    while(check(m,high-1)==true)high--;
    return high;
}

int main(){
    int t,a, n,m, sum;

    while(scanf("%d%d",&n,&m)==2){
        sum=0;
        for(int j=1; j<=n; j++){
            scanf("%d",&a);
            v.push_back(a);
            sum+=a;
        }
        int ans=bisection(m,sum);
        printf("%d\n",ans);
        v.clear();
    }
    return 0;
}

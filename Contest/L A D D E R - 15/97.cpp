#include<bits/stdc++.h>
using namespace std;
#define sz 1001
int arr[sz][6];
vector < int > v, subs[65];

void subsets(int n){
    int cnt=pow(2,n);
    int len=1;
    for(int i=0; i<cnt; i++){
        for(int j=0; j<n; j++){
            if((i&(1<<j))>0)
                subs[len].push_back(j+1);
        }
        len++;
    }
}

int main(){

    int i,j,n,k;
    cin>>n>>k;
    subsets(k);

    for(i=1; i<=k; i++){
        for(j=)
    }

    return 0;
}

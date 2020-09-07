///Date     : 29.4.2020
///Idea     : Put one bishop on black sell and other one on white cell
///Approach : Compute the cumulative sum form the 4 corners
#include<bits/stdc++.h>
using namespace std;
#define sz 2001
#define ll long long

ll a[sz][sz];
ll b[sz][sz];
ll c[sz][sz];
ll d[sz][sz];
ll arr[sz][sz];

void buildA(int i, int j, int n){
    a[i][j]=arr[i][j];
    while(++i<=n && ++j<=n){
        a[i][j]=arr[i][j]+a[i-1][j-1];
    }
}

void buildB(int i, int j, int n){
    b[i][j]=arr[i][j];
    while(++i<=n && --j>=1){
        b[i][j]=arr[i][j]+b[i-1][j+1];
    }
}

void buildC(int i, int j, int n){
    c[i][j]=arr[i][j];
    while(--i>=1 && --j>=1){
        c[i][j]=arr[i][j]+c[i+1][j+1];
    }
}

void buildD(int i, int j, int n){
    d[i][j]=arr[i][j];
    while(--i>=1 && ++j<=n){
        d[i][j]=arr[i][j]+d[i+1][j-1];
    }
}

bool valid(int x, int y, int n){
    return (x>=1 && x<=n && y>=1 && y<=n);
}

int main(){

    int n,i,j;
    scanf("%d",&n);
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            scanf("%lld",&arr[i][j]);
        }
    }
    for(i=1; i<=n; i++){
        ///top left
        buildA(1,i,n);
        buildA(i,1,n);
        ///top right
        buildB(i,n,n);
        buildB(1,n-i+1,n);
        ///bottom left
        buildC(n,n-i+1,n);
        buildC(n-i+1,n,n);
        ///bottom right
        buildD(n,i,n);
        buildD(n-i+1,1,n);
    }

    ll temp, black=-1, white=-1;
    pair < int , int > pw, pb;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            temp=arr[i][j];
            if(valid(i-1,j-1,n))temp+=a[i-1][j-1];
            if(valid(i-1,j+1,n))temp+=b[i-1][j+1];
            if(valid(i+1,j-1,n))temp+=d[i+1][j-1];
            if(valid(i+1,j+1,n))temp+=c[i+1][j+1];

            if((i+j)%2==0 && temp>black){
                black=temp;
                pb={i,j};
            }

            if((i+j)%2==1 && temp>white){
                white=temp;
                pw={i,j};
            }
        }
    }
    cout<<black+white<<endl;
    cout<<pb.first<<' '<<pb.second<<' ';
    cout<<pw.first<<' '<<pw.second<<endl;

    return 0;
}

///Date     : 1.7.2020
///Approach : M

#include<bits/stdc++.h>
using namespace std;
#define sz 55
#define mod 1000000007

int dim;
int I[sz][sz];
int arr[sz][sz];

void mul(int A[sz][sz], int B[sz][sz]){

    int res[sz][sz];

    for(int i=1; i<=dim; i++){
        for(int j=1; j<=dim; j++){
            res[i][j]=0;
            for(int k=1; k<=dim; k++){
                long long int x=(A[i][k]*1LL*B[k][j])%mod;
                res[i][j]=(res[i][j]+x)%mod;
            }
        }
    }
    ///saving into original matrix
    for(int i=1; i<=dim; i++){
        for(int j=1; j<=dim; j++){
            A[i][j]=res[i][j];
        }
    }
}

void power(int A[sz][sz], int n){

    memset(I, 0, sizeof(I));
    for(int i=1; i<=dim; i++)I[i][i]=1;///identity matrix

    ///fast power
    while(n){
        if(n%2)
            mul(I,A),n--;
        else
            mul(A,A),n/=2;
    }

    ///updated the original matrix || Call by Ref
    for(int i=1; i<=dim; i++){
        for(int j=1; j<=dim; j++){
            A[i][j]=I[i][j];
        }
    }
}

void print(int A[sz][sz]){
    for(int i=1; i<=dim; i++){
        for(int j=1; j<=dim; j++){
            cout<<A[i][j]<<' ';
        }
        cout<<endl;
    }
}

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t, n;
    cin>>t;
    while(t--){
        cin>>dim>>n;
        for(int i=1; i<=dim; i++){
            for(int j=1; j<=dim; j++){
                cin>>arr[i][j];
            }
        }
        power(arr, n);
        print(arr);
    }
    return 0;
}

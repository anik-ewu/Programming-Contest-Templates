#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD;

struct matrix{
    ll mat[16][16];
    int row,col;

    matrix(){
        memset(mat,0,sizeof mat);
    }
    matrix(int a, int b){
        row=a,col=b;
        memset(mat,0,sizeof mat);
    }

    matrix operator*(const matrix &p) const{
        assert(col == p.row);
        matrix temp;
        temp.row = row;
        temp.col = p.col;
        for (int i = 0; i < temp.row; i++){
            for (int j = 0; j < temp.col; j++){
                ll sum = 0;
                for (int k = 0; k <col;  k++){
                    sum += ((mat[i][k]%MOD) * (p.mat[k][j]%MOD))%MOD;
                    sum%=MOD;
                }
                temp.mat[i][j] = sum;
            }
        }
        return temp;
    }
    matrix operator+ (const matrix &p) const{
        assert(row==p.row && col==p.col);
        matrix temp;
        temp.row=row;
        temp.col=col;
        for(int i=0;i<temp.row;i++){
            for(int j=0;j<temp.col;j++)
                temp.mat[i][j]=((mat[i][j]%MOD)+(p.mat[i][j]%MOD))%MOD;;
        }
        return temp;
    }

    matrix identity(){
        matrix temp;
        temp.row=row;
        temp.col=col;
        for(int i=0;i<row;i++)
            temp.mat[i][i]=1;
        return temp;
    }

    matrix pow(ll pow){
        matrix temp=(*this);
        matrix ret=(*this).identity();
        while(pow){
            if(pow % 2==1)
                ret=ret*temp;
            temp=temp*temp;
            pow/=2;
        }
        return ret;
    }

    void show(){
        printf("-----------------------------\n");
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++)
                printf("%lld ",mat[i][j]);
            printf("\n");
        }
        printf("-----------------------------\n");
    }
};

/*--------------------------Matrix End---------------------*/

int main(){

    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);

    int t,d,n;
    while(cin>>d>>n>>MOD){
        if(d==0 && n==0 && MOD==0)break;

        matrix base(d,d);
        int j=0;
        for(int i=0; i<d; i++)cin>>base.mat[0][i];
        for(int i=1; i<d; i++)base.mat[i][j]=1,j++;

        matrix temp(d,1);
        for(int i=d-1; i>=0; i--)cin>>temp.mat[i][0];

        int ans;
        if(n<=d){
            ans=temp.mat[d-n][0]%MOD;
        }
        else{
            matrix power=base.pow(n-d);
            power = power*temp;
            ans=power.mat[0][0]%MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}


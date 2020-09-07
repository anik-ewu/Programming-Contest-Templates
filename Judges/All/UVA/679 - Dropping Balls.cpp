#include<bits/stdc++.h>
using namespace std;
int BS(int node, int ball, int max_node){

    int left=node*2;
    int right=node*2+1;

    if(left<max_node && right<max_node){
       if(ball%2==0)return BS(right,ball/2,max_node);/// if balls were even then the sate of the current node is T, balls/2 balls pass the right node
       else return BS(left,ball/2+1,max_node);/// if balls were odd then the state of the current node is F, balls/2 + 1 balls passed the left node
    }
    else
        return node;
}


int main(){

    int minu,n,t,a,m,node,b,ans;
    cin>>t;
    while(t--){
        cin>>a>>b;
        node=1;
        for(int i=1; i<=a; i++)node*=2;
        printf("%d\n",BS(1,b,node));
    }
    cin>>minu;
    return 0;
}

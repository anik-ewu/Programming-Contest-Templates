#include<bits/stdc++.h>
using namespace std;

#define sz 100005
int arr[sz],brr[sz];

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int i,j,n,t,cs=1;

    cin>>t;
    while(t--){
        cin>>n;
        for(i=1; i<=n; i++)cin>>arr[i];
        for(i=1; i<=n; i++)cin>>brr[i];
        stack< int > st;
        j=1;
        for(i=1; i<=n; i++){
            st.push(arr[i]);
            while(!st.empty() && st.top()==brr[j]){
                j++;
                st.pop();
            }
        }
        if(!st.empty()){
            cout<<"Case "<<cs++<<": IMPOSSIBLE"<<endl;
        }
        else{
            cout<<"Case "<<cs++<<": POSSIBLE"<<endl;
        }
    }
    return 0;
}

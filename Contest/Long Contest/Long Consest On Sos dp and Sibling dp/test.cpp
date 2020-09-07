#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, prev, curr, len;
    stack< int > st;
    cin>>n;
    cin>>curr;
    len=0;
    st.push(len);
    for(int i=1; i<n; i++){
       prev=curr;
       cin>>curr;
       if(curr-prev>=2){
        len++;
        if(len==1)len++;
        st.push(len);
       }
       else{
        while(!st.empty()){
            cout<<st.top()<<endl;
            st.pop();
        }
        len=0;
        st.push(len);
       }
    }
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }



    return 0;
}

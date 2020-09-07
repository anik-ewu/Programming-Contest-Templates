///Date     : 4.8.2020
///Approach : Priority Queue
#include<bits/stdc++.h>
using namespace std;

#define sz 30005

int arr[sz];

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    string s;
    int k, id, val;
    priority_queue< pair < int , int > > pq;

    while(cin>>s){
        if(s=="#")break;
        cin>>id>>val;
        arr[id]=val;
        pq.push({-val, -id});
    }
    cin>>k;
    pair< int, int > pii;
    while(k--){
        val=pq.top().first*-1;
        id=pq.top().second*-1;
        pq.pop();
        cout<<id<<endl;
        val+=arr[id];
        pq.push({-val,-id});
    }


    return 0;
}

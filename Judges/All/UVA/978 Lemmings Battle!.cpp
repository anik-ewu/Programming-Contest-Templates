#include<bits/stdc++.h>
#define FastRead   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std ;
int main(){

    ///freopen("out.txt","w",stdout);
    FastRead
    int a, battlefield,blue,green, i,k,t, mx,cs=0;

    cin>>t;
    while(t--){
        cin>>battlefield>>green>>blue;
        priority_queue < int > green_soldier,blue_soldier;
        for(i=1; i<=green; i++){
            cin>>a;
            green_soldier.push(a);
        }
        for(i=1; i<=blue; i++){
            cin>>a;
            blue_soldier.push(a);
        }

        while(green_soldier.size() && blue_soldier.size()){

           vector< int > vg,vb;
           ///find the possible battle field
           k=battlefield;
           mx=green_soldier.size();
           k=min(k,mx);
           mx=blue_soldier.size();
           k=min(k,mx);

           while(k--){
            vg.push_back(green_soldier.top());
            vb.push_back(blue_soldier.top());
            green_soldier.pop();
            blue_soldier.pop();
           }
           for(i=0; i<vg.size(); i++){
                if(vg[i]>vb[i]){
                    green_soldier.push(vg[i]-vb[i]);
                }
                else if(vg[i]<vb[i]){
                    blue_soldier.push(vb[i]-vg[i]);
                }
           }
        }
        if(cs)
            cout<<endl;
        cs=1;
        if(green_soldier.size()){
            cout<<"green wins"<<endl;
            while(!green_soldier.empty()){
                cout<<green_soldier.top()<<endl;
                green_soldier.pop();
            }
        }

        else if(blue_soldier.size()){
            cout<<"blue wins"<<endl;
            while(!blue_soldier.empty()){
                cout<<blue_soldier.top()<<endl;
                blue_soldier.pop();
            }
        }
        else{
            cout<<"green and blue died"<<endl;
        }
    }
     return 0;
}


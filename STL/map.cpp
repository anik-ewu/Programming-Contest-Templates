///Topic : STL [ MAP ]

#include<bits/stdc++.h>
using namespace std;

int main(){
    map < int , int > mp;
    map < int ,int> :: iterator it;
    mp[1]=1;
    mp[5]=5;
    mp[2]=3;

    ///find : memory efficient
    it=mp.find(1);
    if(it==mp.end())
        cout<<"Not Found "<<endl;
    else
        cout<<"found"<<endl;

    ///print in order / sorted
    for(it = mp.begin(); it != mp.end(); it++){
        cout<<it->first<<' '<<it->second<<endl;
    }




    return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define sz 10000002
vector < int > v[sz+5],va;
vector < pair < int , int  >  > vp;

/*pattern
1   2   6   7  15
3   5   8   14
4   9   13
10  12
11
*/

void precal(){

    long long int i,j,k,id;
    v[1].push_back(1);
    vp.push_back(make_pair(1,1));
    for(i=1; i<=sz; i++)
        va.push_back(i);

    j=1;
    for(i=2; j<sz; i++){
        if(i%2==1){
            reverse(va.begin()+j,va.begin()+j+i);
            for(k=1; k<=i; k++){
                v[k].push_back(va[j++]);
                vp.push_back(make_pair(v[k].size(),k));
                if(j+2==sz)break;
            }
        }
        else{
            for(k=1; k<=i; k++){
                v[k].push_back(va[j++]);
                vp.push_back(make_pair(k,v[k].size()));
                if(j+2==sz)break;
            }
        }
    }
}

int main(){

    precal();
    int n,i,j;
    while(cin>>n){

        cout<<"TERM "<<n<<" IS "<<vp[n-1].first<<"/"<<vp[n-1].second<<endl;
    }
    return 0;
}

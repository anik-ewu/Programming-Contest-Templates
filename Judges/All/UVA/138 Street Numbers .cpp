#include<bits/stdc++.h>
using namespace std;

vector < long long int > v,va;

void cal(){

    long long int i=2;
    v.push_back(1);
    v.push_back(6);
    va.push_back(0);
    va.push_back(8);
    printf("%10lld%10lld\n",v[i-1],va[i-1]);

    while(i<11){
     v.push_back(6*v[i-1]-v[i-2]);
     va.push_back(v[i-1]+v[i]+va[i-1]);
     printf("%10lld%10lld\n",v[i],va[i]);
     i++;
    }
}

int main(){

    cal();

    return 0;
}

///Algorithm : Suffix Array 
///Time: n*log(n)*log(n);

#include<bits/stdc++.h>
using namespace std;

void suffix_array_construction(string s){

	s+="$";
	int n=s.size();
	vector< int > p(n), c(n);
	{
		//for k==0
		vector< pair < int, int > > a(n);
		for(int i=0; i<n; i++)a[i]={s[i], i};
		sort(a.begin(), a.end());
		for(int i=0; i<n; i++)p[i]=a[i].second;

		c[p[0]]=0;
		for(int i=1; i<n; i++){
			if(a[i].first==a[i-1].first){
				c[p[i]]=c[p[i-1]];
			}
			else{
				c[p[i]]=c[p[i-1]]+1;	
			}
		}
	}

	int k=0;
	while(( 1<< k)<n){
		
		//k to k+1 transition
		vector< pair< pair < int, int >, int > > a(n);
		for(int i=0; i<n; i++){
			a[i]={{c[i],c[(i+(1<<k))%n]}, i};
		}
		sort(a.begin(), a.end());
		for(int i=0; i<n; i++)p[i]=a[i].second;

		c[p[0]]=0;
		for(int i=1; i<n; i++){
			if(a[i].first==a[i-1].first){
				c[p[i]]=c[p[i-1]];
			}
			else{
				c[p[i]]=c[p[i-1]]+1;	
			}
		}
		k++;
	}
	for(int i=0; i<n; i++)cout<<p[i]<<' ';
	cout<<endl;
}

int main(){

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	string s;
	cin>>s;
	suffix_array_construction(s);


	return 0;
}
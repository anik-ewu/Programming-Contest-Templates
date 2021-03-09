///Algorithm : Suffix Array 
///Time: n*log(n)*log(n);

#include<bits/stdc++.h>
using namespace std;

void count_sort(vector< int >&p, vector< int >&c ){
	
	int n=p.size();
	vector< int > cnt(n);
	for(auto x: c){
		cnt[x]++;
	}

	vector< int > p_new(n);
	vector< int > pos(n);

	pos[0]=0;
	for(int i=1; i<n; i++){
		pos[i]=pos[i-1]+cnt[i-1];
	}

	for(auto x: p){
		int i=c[x];
		p_new[pos[i]]=x;
		pos[i]++;
	}
	p=p_new;

}

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

	   for (int i = 0; i < n; i++) {
        	p[i] = p[i] - (1 << k);
        	if (p[i] < 0)
            	p[i] += n;
        }

		count_sort(p, c);
		
		vector< int >c_new(n); 

		c_new[p[0]]=0;
		for(int i=1; i<n; i++){
			
			pair< int , int > now={c[p[i]], c[(p[i]+(1<<k))%n]};
			pair< int , int > prev={c[p[i-1]], c[(p[i-1]+(1<<k))%n]};

			if(now==prev){
				c_new[p[i]]=c_new[p[i-1]];
			}
			else{
				c_new[p[i]]=c_new[p[i-1]]+1;	
			}
		}
		c=c_new;
		k++;
	}
	for(int i=0; i<n; i++)cout<<p[i]<<' ';
	cout<<endl;
}

int main(){

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	string s;
	cin>>s;
	suffix_array_construction(s);


	return 0;
}
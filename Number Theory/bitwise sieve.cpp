#include<bits/stdc++.h>
using namespace std;

int N =100,prime[100];
int status[(100/32)+2];

int Set(int N,int pos){	return N=N | (1<<pos);}
bool Check(int N,int pos){return (bool)(N & (1<<pos));}

void sieve(){
	 int i, j, sqrtN;
     sqrtN = int( sqrt( N ) );
     for( i = 3; i <= sqrtN; i += 2 ) {
		 if( Check(status[i>>5],i%32)==0){
	 		 for( j = i*i; j <= N; j += (i<<1) ){
				 status[j>>5]=Set(status[j>>5],j%32)   ;
	 		 }
		 }
	 }
	 puts("2");
	 for(i=3;i<=N;i+=2)
		 if( Check(status[i>>5],i%32)==0)
	 	 printf("%d ",i);



int main(){

    sieve();

    return 0;
}

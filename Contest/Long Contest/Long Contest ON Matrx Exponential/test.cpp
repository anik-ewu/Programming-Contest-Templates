#include<bits/stdc++.h>
using namespace std;

void print(int A[3][3]){
    for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
            cout<<A[i][j]<<' ';
		}
		cout<<endl;
    }
}

void multiply(int a[3][3], int b[3][3]){
	int mul[3][3];
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			mul[i][j] = 0;
			for (int k = 0; k < 3; k++)
				mul[i][j] += a[i][k]*b[k][j];
		}
	}

	/// storing the multiplication result in a[][]
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			a[i][j] = mul[i][j]; // Updating our matrix

    cout<<"a :"<<endl;
    print(a);

}
int power(int F[3][3], int n){
	int M[3][3] = {{1,2,3}, {1,2,3}, {1,2,3}};

    cout<<"F :"<<endl;
    print(F);

    cout<<"M :"<<endl;
    print(M);
	multiply(F,M);

    cout<<"F :"<<endl;
	print(F);


}

int findNthTerm(int n){
	int F[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}} ;
	//Base cases
	if(n==0)            return 0;
	if(n==1 || n==2)    return 1;
	return power(F, n-2);
}

int main(){
    int n = 5;
    cout << "F(5) is " << findNthTerm(n);
    return 0;
}

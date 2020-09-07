#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[20];
    int n,b,c,i,j;
    for(i=1; i<=2000; i++)
    {
        gets(a);
        if(a[0]=='#'){break;}
        if(strcmp(a,"HELLO")==0){cout<<"Case "<<i<<": ENGLISH"<<endl;}
        else if(strcmp(a,"HOLA")==0){cout<<"Case "<<i<<": SPANISH"<<endl;}
        else if(strcmp(a,"HALLO")==0){cout<<"Case "<<i<<": GERMAN"<<endl;}
        else if(strcmp(a,"BONJOUR")==0){cout<<"Case "<<i<<": FRENCH"<<endl;}
        else if(strcmp(a,"CIAO")==0){cout<<"Case "<<i<<": ITALIAN"<<endl;}
        else if(strcmp(a,"ZDRAVSTVUJTE")==0){cout<<"Case "<<i<<": RUSSIAN"<<endl;}
        else{cout<<"Case "<<i<<": UNKNOWN"<<endl;}
    }
    return 0;

}
//HELLO
//HOLA
//HALLO
//BONJOUR
//CIAO
//ZDRAVSTVUJTE
//Case 1: ENGLISH
//Case 2: SPANISH
//Case 3: GERMAN
//Case 4: FRENCH
//Case 5: ITALIAN
//Case 6: RUSSIAN

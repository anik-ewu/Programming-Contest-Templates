#include<iostream>
#include<cstdio>
using namespace std;

#define ALPHAPET 26
struct node *root,*curr;
struct node
{
    node* next[ALPHAPET+2];
    int endmark;
    node()
    {
        endmark=0;
        for(int i=0; i<ALPHAPET; i++)
            next[i]=NULL;
    }
};

void insert(char* str)
{
    curr=root;
    bool flag=true;
    for(int i=0; str[i]; i++)
    {
        if(flag)
            printf("%c",str[i]);

        int index=str[i]-'a';
        if(curr->next[index]==NULL)
            flag=false,curr->next[index]=new node();
            curr=curr->next[index];
    }
    curr->endmark++;
    if(flag and curr->endmark>1)
        printf(" %d",curr->endmark);

    puts("");
}


int main()
{

    root=new node();

    char str[100];
    int i,j,k,n;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%s",&str);
        insert(str);
    }



    return 0;
}


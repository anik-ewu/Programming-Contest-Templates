#include<bits/stdc++.h>
using namespace std;
struct node *head,*tail,*current,*temp,*pre;
struct node
{
    int data;
    node *next;
};

void insert()
{
    current=new(struct node);
    current->next=NULL;
    cin>>current->data;
    if(head==NULL)
    {
        head=current;
        tail=current;
    }
    else
    {
        tail->next=current;
        tail=current;
    }
}

void reverse()
{
    pre=NULL;
    current=head;
    while(current!=NULL)
    {
        temp=current->next;
        current->next=pre;
        pre=current;
        current=temp;
    }
    head=pre;
}

void display()
{
    temp=head;
    while(temp!=NULL)
    {

        cout<<temp->data<<' ';
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{

    for(int i=1; i<=5; i++)
        insert();
    display();
    reverse();
    display();


}

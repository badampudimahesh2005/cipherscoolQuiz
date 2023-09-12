

#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};


void insert(node* &head,int val){

    node* n=new node(val);

    if(head==NULL){
        head=n;
        return;

    }
    node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;


}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"NULL"<<endl;

}

node* Group(node* &head){

    node* odd=head;
    node* even=head->next;
    node* evenstart=even;

    while(odd->next!=NULL && even->next!=NULL){
        odd->next=even->next;
        even->next=odd->next->next;

        odd=odd->next;
        even=even->next;
    }
    odd->next=evenstart;
    return head;

 
}

int main(){
    node* head=NULL;

    int n,a;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a;
        insert(head,a);
    }

    display(head);
cout<<endl;
node* newnode=Group(head);
display(newnode);
}
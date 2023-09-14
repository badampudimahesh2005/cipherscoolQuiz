#include<iostream>
using namespace std;


class node{
    public:
    int data;
    node* next;

    node(int val){
        data= val;
        next=NULL;
    }
};


void insert(node* &head,int val){
    node* n= new node(val);

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
    }
    cout<<" NULL"<<endl;
}

node* reverseknodes(node* &head,int k){
    if(head==NULL || k==1){
        return head;
    }
    node* prev=NULL;
    node* curptr=head;
    node* nextptr;

    int count=1;

    while(curptr!=NULL && count<=k){
        nextptr=curptr->next;
        curptr->next=prev;
       
       prev=curptr;
       curptr= nextptr;
       count++;

    }
    if(nextptr!=NULL){
        head->next=reverseknodes(nextptr,k);
    }
    return prev;
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
    int k;
    cin>>k;

    node* newhead= reverseknodes(head,k);
    display(newhead);


}
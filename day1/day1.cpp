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



int twinSum(node* &head,int n){
      
        node* p1 = head;
        node* p2 = head;
        node* prev = nullptr;

        
        for (int i = 0; i < n / 2; i++) {
            p2 = p2->next;
        }

        while (p2) {
            node* next = p2->next;
            p2->next = prev;
            prev = p2;
            p2 = next;
        }

        p2 = prev;

        int max_sum = 0;
        while (p1 && p2) {
            int twin_sum = p1->data + p2->data;
            max_sum = max(max_sum, twin_sum);
            p1 = p1->next;
            p2 = p2->next;
        }
     
        return max_sum;
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
    cout<<twinSum(head,n);
}
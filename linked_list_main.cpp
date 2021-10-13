#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){           //constructor
        data=val;
        next=NULL;
    }
};
void insertAtTail(node* &head,int val){
    node* n=new node(val);

    if(head==NULL){ 
        head=n;
        return;
    }

    node* temp=head;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    
    
}

void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}

void reverse(node* &head){
    node* prev=NULL;
    node* curr=head;
    node* next;

    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        

        prev=curr;
        curr=next;
}
    head=prev;
    
}


bool search(node* head,int key){
    node* temp=head;
    while (temp!=NULL)
    
    {
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
    
}

void deletenode(node* &head,int val){
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

void display(node* head){
    node* temp=head;              //refrence pointer temp initilised by head
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}




int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    display(head);
    insertAtHead(head,4);
    display(head);
    cout<<search(head,5)<<endl;
    deletenode(head,3);
    display(head);
    node* newhead=reverse(head);
    display(newhead);
    return 0;
}
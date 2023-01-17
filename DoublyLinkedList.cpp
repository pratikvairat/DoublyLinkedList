#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node *Next,*prev;
    node(){
        prev=Next=NULL;
    }
};
class Dll{
    private:
        node *Head;
        
    public:
        Dll(){
            Head=NULL;
        }
        void InsertAtHead(int);
        void InsertAtTail(int);
        void Display();
};
void Dll::InsertAtHead(int data){
    node *temp=new node();
    temp->data=data;
    temp->prev=NULL;
    if(Head==NULL){
        Head=temp;
        temp->Next=NULL;
    }else{
        temp->Next=Head;
        Head->prev=temp;
        Head=temp;
    }
    
   
}
void Dll::InsertAtTail(int data){
    node *temp,*curr;
    temp=new node();
    temp->data=data;
    curr=Head;
    if(Head==NULL){
        Head=temp;
    }else{
       while(curr->Next!=NULL){
            curr=curr->Next;
       }
       curr->Next=temp;
       temp->prev=curr;
    }
}

void Dll::Display(){
    node *temp=Head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->Next;
    }
    cout<<endl;
}
int main(){
    Dll dl;
    dl.InsertAtHead(45);
    dl.InsertAtHead(78);
    dl.InsertAtHead(63);
    dl.Display();
    dl.InsertAtTail(74);
    dl.Display();
    return 0;
}
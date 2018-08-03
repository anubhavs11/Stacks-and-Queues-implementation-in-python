#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};
class linked_list{
    struct Node *head;
    public:
    linked_list(){
        head=NULL;
    }
    void insertion_End(int value){
        cout<<"inserting "<<value<<" at the end\n";
        Node *h = head;
        Node *newNode=new Node;
        newNode->data = value;
        newNode->next = NULL;
        if(head==NULL){
            head=newNode;
            head->next=NULL;
        }
        else{
            while(h->next!=NULL){
                h=h->next;
            }
            h->next=newNode;
        }
    }
    void insertion_beg(int value){
        cout<<"inserting "<<value<<" at the beg\n";
        Node *newNode = new Node;
        newNode->data=value;
        newNode->next=head;
        head=newNode;
    }
    void deletion(int value){
        cout<<"Deleting "<<value<<"\n";
        Node *h=head;
        if(head->data==value){
            head=head->next;
        }
        else{
            while(h->next!=NULL){
                if(h->next->data == value){
                    if(h->next->next!=NULL){
                            h->next=h->next->next;
                    }
                    else{
                        h->next=NULL;
                    }
                }
                h=h->next;
            }
        }
    }
    void display(){
        cout<<"Elements : \n";
        Node *h = head;
        if(head==NULL){
            cout<<"Empty";
        }
        while(h!=NULL){
            cout<<h->data<<" ";
            h=h->next;
        }
        cout<<"\n";
    }
};
int main(){
linked_list ob;
ob.insertion_End(3);
ob.insertion_End(4);
ob.insertion_End(5);
ob.insertion_End(6);
ob.display();
ob.deletion(4);
ob.display();
ob.insertion_beg(2);
ob.display();
return 0;
}

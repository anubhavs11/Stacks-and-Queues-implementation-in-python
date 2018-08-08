#include<iostream>
using namespace std;

struct Node{
int data;
struct Node *next;
struct Node *prev;
};
class Linked_List{
    struct Node *head;
    public:
    Linked_List(){
        head=NULL;
    }
    void insertion_end(int value){
        cout<<"Inserting "<<value<<" at the end.\n";
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        if(head==NULL){
            head = newNode;
        }
        else{
            Node *h;
            h=head;
            while(h->next!=NULL){
                h=h->next;
            }
            h->next=newNode;
            newNode->prev = h;
        }
    }
    void insertion_beg(int value){
        cout<<"Inserting "<<value<<" at begning.\n";
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void display(){
        Node *h;
        h = head;
        if(head==NULL){
            cout<<"\n Nothing Found";
        }
        else{
            cout<<"\n Elements: \n";
            while(h!=NULL){
                cout<<h->data<<" ";
                h = h->next;
            }
        }
    }
    void deletion(int value){
            Node *h = head;
            if(head->data == value){
                head = head->next;
                head->prev = NULL;
                cout<<"Deleting "<<value<<" \n";
            }
            else{
                while(h->next!=NULL){
                    if(h->next->data == value){
                        if(h->next->next != NULL){
                            h->next = h->next->next;
                            h->next->prev = h;
                        }
                        else{
                            h->next=NULL;
                        }
                        break;
                    }
                    h = h->next;
                }
            }
    }
};
int main(){
    Linked_List ob;
    ob.insertion_end(2);
    ob.insertion_end(3);
    ob.insertion_beg(1);
    ob.insertion_end(4);
    ob.display();
    ob.deletion(3);
    ob.display();
}

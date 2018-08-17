#include<iostream>
using namespace std;

struct Node{
int data;
struct Node* next;
};

class Linked_List{
    struct Node *head;
    struct Node *tail;
    public:
        Linked_List(){
            head=NULL;
            tail=NULL;
        }
        void insertion(int value){
            Node *newNode = new Node;
            newNode->data = value;
            if(head == NULL){
                cout<<"Added "<<value<<" \n";
                head = newNode;
                tail = newNode;
            }
            else{
                cout<<"inserting "<<value<<" after "<<tail->data<<" \n";
                tail->next = newNode;
                newNode->next = head;
                tail = newNode;
            }
        }
        void display(){
            cout<<"Elements : \n";
            Node *h = head->next;
            cout<<head->data<<" ";
            while(h != head){
                cout<<h->data<<" ";
                h = h->next;
            }
            cout<<"\n";
        }
        void deletion(int value){
                if(head->data == value){
                    cout<<"Deleting "<<value<<"\n";
                    head = head->next;
                    tail->next = head;
                }
                else{
                    Node *h = head;
                    while(h->next != head){
                        if(h->next->data == value){
                            h->next = h->next->next;
                            cout<<"Deleting "<<value<<"\n";
                            break;
                        }
                        h = h->next;
                    }
                }
        }
    };
    int main(){
    Linked_List ob;
    ob.insertion(1);
    ob.insertion(2);
    ob.insertion(3);
    ob.insertion(4);
    ob.display();
    ob.deletion(3);
    ob.display();

    }

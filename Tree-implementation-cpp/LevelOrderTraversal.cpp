#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

class Tree{
    struct Node *root;
public:
    Tree(){
        root = NULL;
    }
    void insertion(struct Node *r,int value){
        if(value < r->data){
            if(r->left == NULL){
                Node *newNode = new Node;
                newNode->data = value;
                newNode->left = NULL;
                newNode->right = NULL;
                r->left = newNode;
            }
            else{
                insertion(r->left , value);
            }
        }
        else{
            if(r->right == NULL){
                Node *newNode = new Node;
                newNode->data = value;
                newNode->left = NULL;
                newNode->right = NULL;
                r->right = newNode;
            }
            else{
                insertion(r->right , value);
            }
        }
    }
    void insert(int value){
        if(root == NULL){
            Node *newNode = new Node;
            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;
            root = newNode;
        }
        else{
           insertion(root,value);
        }
    }
    void display(){
        disp(root);
    }
    void disp(struct Node *h){
        if(h == NULL){
            return;
        }
        disp(h->left);
        cout<<h->data<<" ";
        disp(h->right);
    }
    void levelOrder(struct Node *node){
        queue<Node*> q;
        if(node!=NULL){
            q.push(node);
            while(!q.empty()){
                node = q.front();
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
                cout<<q.front()->data<<" ";
                q.pop();
            }
        }    
    }
    void levelOrderTraversal(){
        levelOrder(root);
    }
};

int main(){
    Tree ob;
    ob.insert(10);
    ob.insert(8);
    ob.insert(6);
    ob.insert(12);
    ob.insert(11);
    ob.display();
    cout<<"\nLevel Order Traversal:";
    ob.levelOrderTraversal();
}

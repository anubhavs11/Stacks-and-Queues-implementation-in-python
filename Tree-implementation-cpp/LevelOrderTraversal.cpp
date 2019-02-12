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
    int getHeight(Node *node){
    	if(!node)
    		return 0;
    	return 1+max(getHeight(node->left),getHeight(node->right));
    }
    int traverse(Node *node,int h,int sum){
    	if(node!=NULL){
    		
    		sum=traverse(node->left,h,sum);
    		sum=traverse(node->right,h,sum);

    		if(getHeight(node)==h){
    			sum+=node->data;
    		}
    	}
    	return sum;
    }
    void ODD_EVEN_LEVEL_DIFFERENCE(){
        int height = getHeight(root);
        int sum_odd = 0;
        int sum_even=0;
        for (int i = 1; i <=height; ++i){
        	if(i%2!=0)
        		sum_odd+=traverse(root,i,0);
        	else
        		sum_even+=traverse(root,i,0);
        }
        cout<<"Difference : "<<abs(sum_odd-sum_even);
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
    
    Tree ob2;
    for (int i = 1; i < 11; ++i)    {
    	ob2.insert(i);
    }
    ob2.ODD_EVEN_LEVEL_DIFFERENCE();
}

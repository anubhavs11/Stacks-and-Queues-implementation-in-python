void mirror(Node* node) 
{
    Node *temp = NULL;
    if(node!=NULL){
        if(node->left!=NULL && node->right!=NULL){
            temp = node->left;
            node->left = node->right;
            node->right = temp; 
        }
        else if(node->left != NULL){
            node->right = node->left ;
            node->left = NULL;
        }
        else if(node->right != NULL){
            node->left = node->right ;
            node->right = NULL;
        }
        mirror(node->left);
        mirror(node->right);
    } 
}

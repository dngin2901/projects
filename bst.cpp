#include "bst.h"

//set node left and right equal to NULL
//data equal to node data
BSTNode::BSTNode(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

BSTNode::~BSTNode(){

}

/*
 * Tree Class Functions
*/

/*
 * Private Functions
*/

// Insert first node if root is NULL
// Insert to the right of root if data is > than
// "root" data. Else insert to the left of root
// if data is < "root" data. Then return the root.
// after insertion
BSTNode* BSTree::insert(int data, BSTNode* root){
     if (this->root == NULL){
        return this->root = new BSTNode(data);
    }

    if(data > root->data)
    {

        if (root->right == NULL)
        {
            root->right = new BSTNode(data);
            return root->right;
        }

        else
        {
           return insert( data, root->right);
        }
    }

    else
    {

        if (root->left == NULL)
        {
            root->left = new BSTNode(data);
            return root->left;
        }

        else
        {
           return insert( data, root->left);
        }
    }

    return root;
}

// return "-1" if tree has only one node
// since adding "1" at the end will return "0"
// for the height
int BSTree::height(BSTNode* root){
    if (root == NULL)
    {
        return -1;
    }

    if( root->left == NULL && root->right == NULL)
    {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    if (left > right)
    {
        return left + 1;
    }

    else
    {
        return right + 1;
    }


}

// same implementation as from binary tree "display_pre_order_helper" function
void BSTree::preorder(BSTNode* root, std::ostream& os){
    if (this->root == NULL)
    {
        return;
    }

    os << root->data <<", ";

    if(root->left != nullptr){
        preorder(root->left, os);
    }

    if(root->right != nullptr){
        preorder(root->right, os);
    }
}

// same implementation as from binary tree "display_in_order_helper" function
void BSTree::inorder(BSTNode* root, std::ostream& os){
    if (this->root == NULL)
    {
        return;
    }
    if (root->left != NULL)
    {
      inorder(root->left, os);
    }

    os << root->data <<", ";

    if (root->right != NULL)
    {
      inorder(root->right, os);
    }
}

// same implementation as from binary tree "display_post_order_helper" function
void BSTree::postorder(BSTNode* root, std::ostream& os){
    if (this->root == NULL)
    {
        return;
    }

    if (root->left != NULL)
    {
        postorder(root->left, os);
    }

    if(root->right != NULL)
    {
        postorder(root->right, os);
    }

    os << root->data <<", ";

}

// destructor function for tree class so tree destructor
// calls this function recursively
void BSTree::destroy(BSTNode* root){
    if(root)
    {
        destroy(root->left);
        destroy(root->right);
        delete root;
    }
}

// If data < root node data check left subtree recursively
// If data > root data check right subtree recursively
bool BSTree::search(int data, BSTNode* root){
    if (root == NULL)
    {
        return false;
    }

    if (root->data == data)
    {
        return true;
    }

    if (data < root->data)
    {
        return search(data, root->left);
    }

    else
    {
        return search(data, root->right);
    }

    return NULL;
}

// if BST is equal to NULL than return true.
// if a node left or right subtree is emtpy return true.
// if a node has left and right children check if the
// children also have children recursively.
bool BSTree::isFull(BSTNode* root){
    if(root == NULL)
    {
        return true;
    }

    if(root->left == NULL && root->right == NULL)
    {
        return true;
    }

    if((root->left) && (root->right))
    {
        return (isFull(root->left) && isFull(root->right));
    }

    return false;
}


// check if the BST is complete first by if BST is empty return true
// if index of current node is higher than node count return false
//recursively check for the same condition on left and right subtree
bool BSTree::isComplete(BSTNode* root, int index, int node_count){
    if (root == NULL)
    {
        return true;
    }

    if(index >= node_count)
    {
        return false;
    }

    return (isComplete(root->left, 2*index + 1, node_count) &&
          isComplete(root->right, 2*index + 2, node_count));

}



/*
 * Public Functions
*/

// constructor for tree class setting the root to NULL
BSTree::BSTree(){
    this->root = nullptr;
}

// destructor for tree class calling "destroy" function
// recursively
BSTree::~BSTree(){
    destroy(root);
}

//counter function for every node in the bst
int BSTree::countNodes(BSTNode* root){
    if(root == NULL)
    {
        return 0;
    }
    return (1 + countNodes(root->left) + countNodes(root->right));
}

// calls on insert private function and supplies the data
void BSTree::insert(int data){
    insert(data, this->root);
}

//returns height private fuction
int BSTree::height(){
    return height(this->root);
}

// calls preorder private function
void BSTree::preorder(std::ostream& os){
    preorder(this->root, os);
    os<<std::endl;
}

// calls inorder private function
void BSTree::inorder(std::ostream& os){
    inorder(this->root, os);
    os<<std::endl;
}

//calls postorder private function
void BSTree::postorder(std::ostream& os){
    postorder(this->root, os);
    os<<std::endl;
}

// calls search private function and supplies the data
bool BSTree::search(int data){
    return search(data, this->root);
}

//return the isFull private function
bool BSTree::isFull(){
    return isFull(this->root);
}

//return the isComplete private function
bool BSTree::isComplete(int index, int node_count){
    return isComplete(this->root, index, node_count);
}

//return the countNodes private function
int BSTree::countNodes(){
    return countNodes(this->root);
}
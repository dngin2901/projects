#include "heap.h"

/*
 * Node Class Functions
*/

HeapNode::HeapNode(int data){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

HeapNode::~HeapNode(){

}

/*
 * Tree Class Functions
*/

/*
 * Private Functions
*/

HeapNode* HeapTree::insert(int data, HeapNode* root){
    if(root == nullptr){
        return new HeapNode(data);
    }

    if(data < root->data){
        int temp = root->data;
        root->data = data;
        data = temp;
    }


    if((isFull(root) && size(root->left) == size(root->right))|| !isFull(root->left)){
        root->left = insert(data, root->left);
    }else{
        root->right = insert(data, root->right);
    }

    return root;
}

int HeapTree::height(HeapNode* root){
    if(root == nullptr){
        return -1;
    }

    int left = height(root->left);
    int right = height(root->right);

    if(left > right){
        return left + 1;
    }else{
        return right + 1;
    }
}

void HeapTree::preorder(HeapNode* root, std::ostream& os){
    if(root == nullptr){
        return;
    }

    os << root->data << ", ";
    preorder(root->left, os);
    preorder(root->right, os);
}

void HeapTree::inorder(HeapNode* root, std::ostream& os){
    if(root == nullptr){
        return;
    }

    inorder(root->left, os);
    os << root->data << ", ";
    inorder(root->right, os);
}

void HeapTree::postorder(HeapNode* root, std::ostream& os){
    if(root == nullptr){
        return;
    }

    postorder(root->left, os);
    postorder(root->right, os);
    os << root->data << ", ";
}

void HeapTree::destroy(HeapNode* root){

}

bool HeapTree::search(int data, HeapNode* root){
    if(root == nullptr){
        return false;
    }

    if(root->data == data){
        return true;
    }

    if(data < root->data){
        return search(data, root->left);
    }else if(data > root->data){
        return search(data, root->right);
    }

    return false;
}

bool HeapTree::isFull(HeapNode* root){
    if(root == nullptr){
        return true;
    }
    // Handle leaf node logic
    if(root->left == nullptr && root->right == nullptr){
        return true;
    }

    // If this node has two children & they are both Full, return true
    if(root->left != nullptr && root->right != nullptr){
        return isFull(root->left) && isFull(root->right);
    }

    return false;
}

// Index each node & compare it to the # of Nodes in the tree.
// If any node's index is >= the # of nodes we have, the tree is incomplete.
/*
         0
    1        2
3       4 5     6
*/
bool HeapTree::isComplete(HeapNode* root, int index, int node_count){
    if(root == nullptr){
        return true;
    }

    if(index >= node_count){
        return false;
    }

    bool left_complete = isComplete(root->left, 2*index + 1, node_count);
    bool right_complete = isComplete(root->right, 2*index + 2, node_count);

    return left_complete && right_complete;
}

int HeapTree::size(HeapNode* root){
    if(root == nullptr){
        return 0;
    }

    int left_size = size(root->left);
    int right_size = size(root->right);

    return left_size + right_size + 1;
}

HeapNode* HeapTree::min_heapify(HeapNode* root){
    if(root == nullptr){
        return nullptr;
    }

	if (root->left != nullptr)
	{
	    if(root->left->data < root->data)
	    {
    	    int temp = root->data;
    	    root->data = root->left->data;
    	    root->left->data = temp;
	    }

	root->left = min_heapify(root->left);
	}

    if(root->right != nullptr)
    {
        if(root->right->data < root->data)
        {
            int temp2 = root->data;
            root->data = root->right->data;
            root->right->data = temp2;
        }

    root->right = min_heapify(root->right);
    }

    return root;
}

HeapNode* HeapTree::find_last(HeapNode* root, int index, int node_count){
    if(root == nullptr || index >= node_count){
        return nullptr;
    }

	if(index == node_count - 1)
	{
	    return root;
	}

	if(2*index + 1 == node_count - 1)
	{
	    HeapNode* temp;
	    temp = root->left;
	    root->left = nullptr;
	    return temp;
	}

	if(2*index + 2 == node_count - 1)
	{
	    HeapNode* temp;
	    temp = root->right;
	    root->right = nullptr;
	    return temp;
	}

    HeapNode* temp = find_last(root->left, 2*index + 1, node_count);

    if(temp)
    {
        return temp;
    }

    return find_last(root->right, 2*index + 2, node_count);
}

void HeapTree::remove_min(HeapNode* root){

    HeapNode* temp = find_last(this->root, 0, size(this->root));
    root->data =  temp->data;
    delete temp;

}

void HeapTree::delete_element(int data, HeapNode* root){
    if(root == nullptr){
        return;
    }

    if(root->data == data)
    {
        HeapNode* temp = find_last(this->root, 0, size(this->root));
        std::swap(root->data, temp->data);
        delete temp;
        return;
    }

        delete_element (data, root->left);
        delete_element(data, root->right);
}

/*
 * Public Functions
*/

HeapTree::HeapTree(){
    this->root = nullptr;
}

HeapTree::~HeapTree(){
    destroy(this->root);
}

void HeapTree::insert(int data){
    this->root = insert(data, this->root);
}

int HeapTree::height(){
    return height(this->root);
}

void HeapTree::preorder(std::ostream& os){
    preorder(this->root, os);
    os << "\n";
}

void HeapTree::inorder(std::ostream& os){
    inorder(this->root, os);
    os << "\n";
}

void HeapTree::postorder(std::ostream& os){
    postorder(this->root, os);
    os << "\n";
}

bool HeapTree::search(int data){
    return search(data, this->root);
}

bool HeapTree::isFull(){
    return isFull(this->root);
}

bool HeapTree::isComplete(){
    return isComplete(this->root, 0, size(this->root));
}

void HeapTree::remove_min(){
    remove_min(this->root);
    min_heapify(this->root);
}

void HeapTree::delete_element(int data){
    delete_element(data, this->root);
     min_heapify(this->root);
}

// Strictly used for the test cases
void HeapTree::find_last(std::ostream& os){
    HeapNode* temp = find_last(this->root, 0, size(this->root));
    os << temp->data << std::endl;
}


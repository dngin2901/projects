#ifndef __BINTREE_H__
#define __BINTREE_H__

#include <iostream>
#include <ostream>

#ifndef NULL
#define NULL 0x00
#endif
// Defines MAX
// When used, MAX(a,b) will be replaced with ((a > b) ? a : b)
#ifndef MAX
#define MAX(a,b) ((a > b) ? a : b)
#endif

// Underlying class which will be used to implement the HeapTree class.
// I.E. HeapTree is made up of HeapNode
class HeapNode
{
    private:
        int data;
        HeapNode* left;
        HeapNode* right;

    public:
        HeapNode(int data);
        ~HeapNode();

    friend class HeapTree;
};
// Please note that test.cpp shows that insert and remove methods
// only take one parameter (an integer).
// This means you will need to have a private and public version of some methods:
// A private function would take a pointer to the root node of the tree and the
// integer to be inserted/removed.
// A public version would only take the integer to be inserted/removed as a
// parameter and then use the private version of the method to implement.
class HeapTree
{
    private:
        HeapNode* root;

        HeapNode* insert(int data, HeapNode* root);
        int height(HeapNode* root);

        void preorder(HeapNode* root, std::ostream& os);
        void inorder(HeapNode* root, std::ostream& os);
        void postorder(HeapNode* root, std::ostream& os);

        void destroy(HeapNode* root);
        bool search(int data, HeapNode* root);

        bool isComplete(HeapNode* root, int index, int node_count);
        bool isFull(HeapNode* root);
        int size(HeapNode* root);

        void remove_min(HeapNode* root);
        void delete_element(int data, HeapNode* root);

        HeapNode* min_heapify(HeapNode* root);
        HeapNode* find_last(HeapNode* root, int index, int node_count);

    public:
        HeapTree();
        ~HeapTree();

        void insert(int data);
        int height();

        void preorder(std::ostream& os = std::cout);
        void inorder(std::ostream& os = std::cout);
        void postorder(std::ostream& os = std::cout);

        bool search(int data);

        bool isComplete();
        bool isFull();

        void remove_min();
        void delete_element(int data);

        void find_last(std::ostream& os = std::cout);
};

#endif
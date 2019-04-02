/**
 * Header file for class "Tree".
 */
#include <iostream>
// #include "Node.hpp"
using namespace std;


namespace ariel {



class Tree {

    private:
        /* Node struct */
        struct Node{
        int data;
        Node *left, *right;
    };
        /* private data members */
        Node* t_root;
        int t_size;

        /* private methods */
        void removeSubTree(Node* ptr);//private method- removes the sub-tree.
        bool insert_help(Node *root, int data);//help method.
        Tree::Node* search_node(Node *root,int val);//help method.
        void print_inorder(Node *root);//help method.
        Tree::Node* parent_help(Node *root,int val);//help method.
        bool remove_help(int val, Node* parent);//help method.
        int find_small(Node* ptr);//help method
        bool removeRoot();//private method remove the root node.
        bool removeMatch(Node* parent, Node* match, bool left);//private method remove node.

    public:
        /* "outline" constructor. */
        Tree(); 
        /* "outline" destructor. */ 
        ~Tree();

        /* public "outline" methods */
        bool insert(int data);
        bool remove(int data);
        int size();
        bool contains(int data);
        int root();
        int parent(int data);
        int left(int data);
        int right(int data);
        void print();
        

};
}

/**
 * Header file for class "Tree".
 */
#include <iostream>
// #include "Node.hpp"
using namespace std;


namespace ariel {
    struct Node{
        int data;
        Node *left, *right;
};


class Tree {
    private:
        Node* t_root;
        int t_size;

        

        bool insert_help(Node *root, int data);//help method.
        Node* search_node(Node *root,int val);//help method.
        void print_inorder(Node *root);//help method.
        Node* parent_help(Node *root,int val);//help method.
        bool remove_help(Node *parent, Node *cur);//help method.
        Node* find_max(Node *cur);//help method

    public:
        /* "outline" constructor. */
        Tree(); 

        /* "outline" methods */
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
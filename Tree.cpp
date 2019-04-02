/**
 * Implementation file of class "Tree"
 */

#include <iostream>
#include <cstdlib>
#include "Tree.hpp"
#include <stdexcept>
using namespace ariel;

/* "outline" constructor implementation: */
Tree::Tree(){
    this->t_root = NULL;
    this->t_size = 0;
}
/* "outline" destructor implementation: */
Tree::~Tree(){
    removeSubTree(this->t_root);
}

/* private method - removes all the sub-tree. */
void Tree::removeSubTree(Node* ptr){
    if(ptr != NULL){
        if(ptr->left != NULL){
            removeSubTree(ptr->left);
        }
        if(ptr->right != NULL){
            removeSubTree(ptr->right);
        }
        delete ptr;
    }
}


/* "outline" method implementation: */
/* This method adds a node to the tree */
bool Tree::insert(int data){
    if (this->t_root == NULL){
        this->t_root = new Node{data , NULL, NULL};
        this->t_size++;
        return true;
    }
    else if(this->contains(data)){
        throw std::invalid_argument("You cannot add the same value twice!!");
        return false;
    }
    else
    {
        this->t_size++;
        return this->Tree::insert_help(this->t_root, data);
    }
}


bool Tree::remove(int data){
  return this->remove_help(data,this->t_root);
}

/* This method returns tree size. */
int Tree::size(){
    return this->t_size;
}

bool Tree::contains(int data){
    if(Tree::search_node(this->t_root, data) != NULL){
        return true;
    }
    return false;
}

/* This method returns the value of the root. */
int Tree::root(){
    if(this->t_root != NULL){
        return this->t_root->data;
    }
    else{
        throw std::invalid_argument("The tree is empty - there is no root!!");
    }
    
}

int Tree::parent(int data){
    Node *temp = this->parent_help(this->t_root, data);
    if(temp == NULL){
        throw std::invalid_argument("There is no parent in the tree for this data!!");
    }
    return temp->data;
}

/**
 * This method returnt the value of the left child of the value.
 * If no child or parent exist throws exception.
 * */
int Tree::left(int data){
    Node *temp = this->search_node(this->t_root, data);
    if(temp == NULL){
         throw std::invalid_argument("There is no node whith this value!!");
    }
    if(temp->left != NULL){
        return temp->left->data;
    }
    throw std::invalid_argument("There is no left child!!");
}

/**
 * This method returnt the value of the right child of the value.
 * If no child or parent exist throws exception.
 * */
int Tree::right(int data){
    Node *temp = this->search_node(this->t_root, data);
    if(temp == NULL){
        throw std::invalid_argument("There is no node whith this value!!");
    }
    if(temp->right != NULL){
        return temp->right->data;
    }
    throw std::invalid_argument("There is no right child!!");
}

void Tree::print(){
    Tree::print_inorder(this->t_root);
    cout << endl;
}


bool Tree::insert_help(Node *root, int val){
    if (root->data > val){
        if (!root->left){
            root->left = new Node{val, NULL, NULL};
            return true;
        }
        else{
            insert_help(root->left, val);
        }
    }
    else{
        if (!root->right){
            root->right = new Node{val, NULL, NULL};
            return true;
        }
        else{
            insert_help(root->right, val);
        }
    }
    return false; // never reached
}

/* Ruturns the node with the wanted value - if any */
Tree::Node* Tree::search_node(Node *root, int val){
    if(root == NULL){
        return NULL;
    }
    else if(root->data == val){
        return root;
    }
    else if(root->data < val){
        return search_node(root->right, val);
    }
    else{
        return search_node(root->left, val);
    }
    return root; // never reached
}

/* Prints the tree inorder */
void Tree::print_inorder(Node *root){
    if(root == NULL){
        return;
    }
    print_inorder(root->left);
    cout << root->data << " ";
    print_inorder(root->right);
}


/* Ruturns the parent of the node with the wanted value - if any */
Tree::Node* Tree::parent_help(Node *root, int val){
    if(root == NULL){
        return NULL;
    }
    else if(root->right != NULL && root->right->data == val){
        return root;
    }
    else if(root->left != NULL && root->left->data == val){
        return root;
    }
    else if(root->data < val){
        return parent_help(root->right, val);
    }
    else{
        return parent_help(root->left, val);
    }
    return NULL;
}
/* Remove method- recives value to delete and apointer to nod,
    finds the nood with the same value and remove it from the tree.
    this mothod throw exception if try to remove from an empty tree and
     if the value doesnt exist in the tree.
     based on : https://www.youtube.com/watch?list=PLTxllHdfUq4d-DE16EDkpeb8Z68DU7Z_Q&time_continue=210&v=ZuRwTb7ZdWk */
bool Tree::remove_help(int val, Node* parent){
    /* If the tree not empty. */
    if(this->t_root != NULL){
        /* Delete root case. */
        if(this->t_root->data == val){
            return removeRoot();
        }
        /* The node that we want to remove - not root node.  */
        else{
            /* Left sub-tree */
            if(val < parent->data && parent->left != NULL){
                if(parent->left->data == val){
                    return removeMatch(parent, parent->left, true);
                }
                else{  
                    return remove_help(val, parent->left);
                }
                
            }
            /* Right sub-tree */
            else if(val > parent->data && parent->right != NULL){
                if(parent->right->data == val){
                    return removeMatch(parent, parent->right, false);
                }
                else{
                    return remove_help(val, parent->right);
                }
                
            }
            /* The value not in the tree. */
            else{
                 throw std::invalid_argument("The data was not found in the tree!!");
            }

        }
    }
    /* If the tree empty. */
    else{
        throw std::invalid_argument("Cannot remove a node from an empty tree!!");
    }
    return false;
    }
    


/* Find smallest value in the Tree */ 
int Tree::find_small(Node* ptr){
    /* If the tree if empty. */
    if(this->t_root == NULL){
        throw std::invalid_argument("The tree is empty - there is no smallest value!!");
    }
    /* The roon isnt empty. */
    else{
        if(ptr->left != NULL){
            return find_small(ptr->left);
        }
        /* Reache to the smallest node. */
        else{
            return ptr->data;
        }
    }

}
/* private method - removes the root node. */
bool Tree::removeRoot(){
    /* If the root exist. */
    if(this->t_root != NULL){
        Node* delPtr = this->t_root;
        int rootKey = this->t_root->data;
        int smallestInRightSubTree;

        /* If the root have 0 child */
        if(this->t_root->left == NULL && this->t_root->right == NULL){
            this->t_root = NULL;
            delete delPtr;
            this->t_size--;
            return true;
        }
        /* If the root have 1 child */ 
        else if(this->t_root->left == NULL && this->t_root->right != NULL){
           this->t_root = this->t_root->right;
           delPtr->right = NULL;
           delete delPtr;
           this->t_size--;
           return true; 
        }
        else if(this->t_root->left != NULL && this->t_root->right == NULL){
           this->t_root = this->t_root->left;
           delPtr->left = NULL;
           delete delPtr;
           this->t_size--;
           return true; 
        }

        /* If the root have 2 child */
        else{
            smallestInRightSubTree = this->find_small(this->t_root->right);
            this->remove_help(smallestInRightSubTree, this->t_root);
            this->t_root->data = smallestInRightSubTree;
        }
    }
    /* If the root doesnt exist - throw exception. */
    else{
        throw std::invalid_argument("Can not remove root, the tree is empty!!");
    }
    return false;
}

bool Tree::removeMatch(Node* parent, Node* match, bool left){
    /* If the tree isnt empty. */
    if(this->t_root != NULL){
        Node* delPtr;
        int matchVal = match-> data;
        int smallestInRightSubTree;

        /* The node that we want to delete have 0 children. */
        if(match->left == NULL && match->right == NULL){
            delPtr = match;
            if(left){
                parent->left = NULL;
            }
            else{
                parent->right = NULL;
            }  
             
            delete delPtr;
            this->t_size--;
            return true;
        }

        /* The node that we want to delete have 1 children. */
        else if(match->left == NULL && match->right != NULL){
            if(left){
                parent->left = match->right;
            }
            else{
                parent->right = match->right;
            }   
            match->right = NULL;
            delPtr = match;
            delete delPtr;
            this->t_size--;
            return true;
        }

        else if(match->left != NULL && match->right == NULL){
            if(left){
                parent->left = match->left;
            }
            else{
               parent->right = match->left; 
            }
            match->left = NULL;
            delPtr = match;
            delete delPtr;
            this->t_size--;
            return true;
        }
        /* The node that we want to delete have 2 children. */
        else{
            smallestInRightSubTree = this->find_small(match->right);
            this->remove_help(smallestInRightSubTree,match );
            match->data = smallestInRightSubTree;
        }


        
    }
    /* If the tree is empty. */
    else{
       throw std::invalid_argument("Can not remove nodefrom an empty tree!!"); 
    }
    return false;
}

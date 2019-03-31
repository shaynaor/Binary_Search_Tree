/**
 * Implementation file of class "Tree"
 */

#include "Tree.hpp"
#include <stdexcept>
using namespace ariel;

/* "outline" constructor implementation: */
Tree::Tree(){
    this->t_root = NULL;
    this->t_size = 0;
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
    Node *cur = search_node(this->t_root, data);
   Node *parent = parent_help(this->t_root, data);
   return this->Tree::remove_help(parent,cur);
   return true;
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
    return this->t_root->data;
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
Node* Tree::search_node(Node *root, int val){
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
Node* Tree::parent_help(Node *root, int val){
    // if(root == NULL){
    //     return NULL;
    // }
    // else if(root->right != NULL && root->right->data == val){
    //     return root;
    // }
    // else if(root->left != NULL && root->left->data == val){
    //     return root;
    // }
    // else if(root->data < val){
    //     return search_node(root->right, val);
    // }
    // else{
    //     return search_node(root->left, val);
    // }
    return NULL; // never reached
}

bool Tree::remove_help(Node *parent, Node *cur){
    // /* The value doesnt exist int the tree */
    // if(cur == NULL){
    //     throw std::invalid_argument("This value doesnt exist!!");
    // }
    // if(this->t_size == 1){
    //     delete this->t_root;
    //     this->t_size--;
    //     return true;
    // }
    // /* The value has no children */
    // if(cur->left == NULL && cur->right == NULL){

    //     if(parent != NULL && parent->left != NULL && parent->left->data == cur->data){
    //         parent->left = NULL;
    //         delete cur;
    //         this->t_size--;
    //         return true;
    //     }

    //     if(parent != NULL && parent->right != NULL && parent->right->data == cur->data){
    //         parent->right = NULL;
    //         delete cur;
    //         this->t_size--;
    //         return true;
    //     }
    //     /* If no parent and no children then only root exist */
    //     else{
    //         delete cur;
    //         this->t_size--;
    //         return true;
    //     }
    //  }
    //  /* If only left child */
    //  if(cur->left != NULL && cur->right == NULL){
    //      Node *temp = cur->left;
    //      parent->left = temp;
    //      delete cur;
    //      this->t_size--;
    //      return true;
    //  }
    // /* If only right child */ 
    //  if(cur->right != NULL && cur->left == NULL){
    //     Node *temp = cur->right;
    //     parent->right = temp;
    //     delete cur;
    //     this->t_size--;
    //     return true;
    //  }
    // /* Two child case */
    // if(cur->right != NULL && cur->left != NULL ){
    //     Node *maxNode = this->find_max(cur->left);
        
    //     /* If maxNode has a left child */
    //     if(maxNode != NULL && maxNode->left != NULL){
    //         Node *maxParent = this->parent_help(this->t_root,maxNode->data);
    //         if(maxParent != NULL){
    //             /* If not root */
    //             if(parent != NULL){
    //                maxParent->right = maxNode->left;
    //                 parent->left = maxNode;
    //                 maxNode->left = cur->left;
    //                 maxNode->right = cur->right;
    //                delete cur;
    //                 this->t_size--;
    //                 return true;   
    //             }
    //             /* If root */
    //             else{
    //                maxParent->right = maxNode->left;
    //                 this->t_root->data = maxNode->data;
    //                delete maxNode;
    //                 this->t_size--;
    //                 return true;
    //             }
               
    //         }

    //     }
    //     /* If max has no left child */
    //     else{
    //         /* If not root */
    //         if(parent != NULL){
    //             parent->left = maxNode;
    //             maxNode->left = cur->left;
    //             maxNode->right = cur->right;
    //             delete cur;
    //             this->t_size--;
    //             return true;  
    //         }
    //         /* If root */
    //         else{ 
                
    //         }

    //         }
    //     }
    
     
    return false;
    }
    



Node* Tree::find_max(Node* cur){
    Node *runner = cur;
    while(runner->right != NULL){
        runner = runner->right;
    }
    return runner;
}

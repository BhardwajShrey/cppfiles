#include "binary_tree_node.h"

class binary_tree {
    private:
        int size;
    public:
        binary_tree_node* root;
        // functions
        binary_tree(int*, int, int); // build from array
        int get_size();
        void increase_size(int);
        void inorder();
        // void preorder();
        // void postorder();
        void level_order();
        void insert_after(binary_tree_node*, binary_tree_node*); // insert new node after specified node in inorder traversal
        int subtree_delete(binary_tree_node*); // deletes node from tree and returns its data
};

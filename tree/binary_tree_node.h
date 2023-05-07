#pragma once

class binary_tree_node {
    private:
        int data;
    public:
        binary_tree_node* left;
        binary_tree_node* right;
        binary_tree_node* parent;
        // functions
        binary_tree_node(int);
        int get_data();
        void set_data(int);
        void print_parent_data();
        binary_tree_node* subtree_first(); // in subtree of node, return node which comes first in inorder
        binary_tree_node* successor(); // return node which comes next in inorder
};

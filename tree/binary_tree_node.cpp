#include<iostream>
#include "binary_tree_node.h"

using namespace std;

binary_tree_node::binary_tree_node(int data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
}

int binary_tree_node::get_data() {
    return this->data;
}

void binary_tree_node::set_data(int data) {
    this->data = data;
}

void binary_tree_node::print_parent_data() {
    if (this->parent == NULL) {
        printf("No parent present for current node.\n");
    } else {
        printf("Parent for current node: %d\n", this->parent->get_data());
    }
}

binary_tree_node* binary_tree_node::subtree_first() {
    binary_tree_node* temp = this;

    while (temp->left != NULL) {
        temp = temp->left;
    }

    return temp;
}

binary_tree_node* binary_tree_node::successor() {
    if (this->right != NULL) {
        return this->right;
    } else {
        binary_tree_node* temp = this;

        while (temp->parent != NULL && temp->parent->left != temp) {
            temp = temp->parent;
        }

        return temp->parent;
    }
}

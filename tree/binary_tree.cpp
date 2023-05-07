#include <climits>
#include<iostream>

#include "binary_tree_node.cpp"
#include "binary_tree.h"
#include "binary_tree_node.h"

using namespace std;

binary_tree_node* construct_tree(int* arr, int i, int n, binary_tree_node* parent) {
    if (i >= n || arr[i] == INT_MAX) {
        return NULL;
    } else {
        binary_tree_node* root = new binary_tree_node(arr[i]);
        root->parent = parent;

        root->left = construct_tree(arr, 2*i + 1, n, root);
        root->right = construct_tree(arr, 2*i + 2, n, root);

        return root;
    }
}

binary_tree::binary_tree(int* arr, int size_of_array, int size_of_tree) {
    this->root = construct_tree(arr, 0, size_of_array, NULL);
    this->increase_size(size_of_tree);
}

void inorder_helper(binary_tree_node* root) {
    if (root == NULL) {
        return;
    } else {
        inorder_helper(root->left);
        printf("%d ", root->get_data());
        inorder_helper(root->right);
    }
}

void binary_tree::inorder() {
    printf("Inorder traversal: ");
    inorder_helper(this->root);
    printf("\n\n");
}

int binary_tree::get_size() {
    return this->size;
}

void binary_tree::increase_size(int n) {
    this->size += n;
}

int main () {
    int ar[] = {1, 2, 3, 4, 5, INT_MAX, INT_MAX, 6, INT_MAX, INT_MAX, INT_MAX};
    binary_tree tree1 = binary_tree(ar, 11, 6);
    tree1.inorder();
    printf("Size of tree: %d\n\n", tree1.get_size());

    return 0;
}

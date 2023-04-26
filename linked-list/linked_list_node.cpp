#include"linked_list_node.h"

node::node(int input) {
    this->data = input;
}

void node::set_data(int input) {
    this->data = input;
}

int node::get_data() {
    return this->data;
}

#pragma once

class node {
    private:
        int data;
    public:
        node* next;
        node(int);
        void set_data(int);
        int get_data();
};

#include"linked_list_node.h"

class linked_list {
    private:
        int length;
    public:
        node* head;
        node* tail;
        // functions
        linked_list();
        int len();
        void increase_len(int);
        void iter_seq();
        int get_at(int);
        void set_at(int, int);
        int get_head();
        int get_tail();
        void insert_at(int, int);
        int delete_at(int);
        void insert_at_beginning(int);
        int delete_at_beginning();
        void insert_at_end(int);
};

#include <cstdio>
#include<iostream>

#include"linked_list_node.cpp"
#include"linked_list.h"

using namespace std;

linked_list::linked_list() {
    this->head = NULL;
    this->tail = NULL;
    this->length = 0;
}

int linked_list::len() {
    return this->length;
}

void linked_list::increase_len(int val) {
    this->length += val;
}

void linked_list::iter_seq() {
    node* temp = this->head;

    while (temp != NULL) {
        printf("%d -> ", temp->get_data());
        temp = temp->next;
    }
    printf("()\n");
    printf("Length of list is: %d\n", this->len());
}

int linked_list::get_head() {
    if (head == NULL) {
        cerr<<"Head is NULL. Cannot fetch data...\n";
        return -1;
    }
    return head->get_data();
}

int linked_list::get_tail() {
    if (tail == NULL) {
        cerr<<"Tail is NULL. Cannot fetch data...\n";
        return -1;
    }
    return tail->get_data();
}

void linked_list::insert_at_beginning(int val) {
    node* temp = new node(val);
    temp->next = head;

    head = temp;
    this->increase_len(1);

    // very first element to be inserted
    if (head->next == NULL) {
        this->tail = head;
    }
}

int linked_list::delete_at_beginning() {
    if (head == NULL) {
        cerr<<"Can't perform deletion on null list...\n";
        return -1;
    }

    int val_deleted = head->get_data();
    this->increase_len(-1);
    head = head->next;
    if (head == NULL) {
        tail = NULL;
    }

    return val_deleted;
}

int linked_list::get_at(int i) {
    if (i >= this->len()) {
        fprintf(stderr, "Index %d falls outside length %d of the list. Cannot fetch element...\n", i, this->len());
        return -1;
    }
    node* temp = head;
    while (i > 0) {
        temp = temp->next;
        i--;
    }
    return temp->get_data();
}

void linked_list::set_at(int i, int x) {
    if (i >= this->len()) {
        fprintf(stderr, "Index %d falls outside length %d of the list. Cannot set element...\n", i, this->len());
        return;
    }
    node* temp = head;
    while (i > 0) {
        temp = temp->next;
        i--;
    }
    temp->set_data(x);
}

void linked_list::insert_at_end(int val) {
    node* temp = new node(val);
    if (tail != NULL) {
        tail->next = temp;
    }
    tail = temp;
    increase_len(1);

    if (head == NULL) {
        head = temp;
    }
}

void linked_list::insert_at(int i, int x) {
    if (i >= this->len()) {
        this->insert_at_end(x);
        return;
    } else if (i == 0) {
        this->insert_at_beginning(x);
        return;
    }
    node* new_node = new node(x);
    node* temp = head;

    while (i > 1) {
        temp = temp->next;
        i--;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    this->increase_len(1);
}

int linked_list::delete_at(int i) {
    if (i >= this->len()) {
        fprintf(stderr, "Index %d is out of bounds for length %d...\n", i, this->len());
        return -1;
    } else if (this->len() == 0) {
        fprintf(stderr, "Cannot delete anything from an empty list innit...\n");
        return -1;
    } else if (i == 0) {
        return this->delete_at_beginning();
    }

    node* temp = head;
    while (i > 1) {
        temp = temp->next;
        i--;
    }
    int deleted_val = temp->next->get_data();
    if (temp->next == tail) {
        tail = temp;
    }
    temp->next = temp->next->next;
    this->increase_len(-1);
    return deleted_val;
}

void construct_list(linked_list* ll, int n) {
    for(int i = n; i >= 0; i--) {
        ll->insert_at_beginning(i);
    }
}

int main() {
    printf("Driver function for linked-lists.\n");

    linked_list* ll1 = new linked_list();
    ll1->delete_at(0);
    // construct_list(ll1, 15);
    // ll1->insert_at_end(69);
    // ll1->iter_seq();
    // ll1->insert_at(10, 100);
    // ll1->insert_at(0, 101);
    // ll1->iter_seq();
    ll1->delete_at(11);
    ll1->iter_seq();

    return 0;
}

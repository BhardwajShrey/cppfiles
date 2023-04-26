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
    printf("NULL\n");
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

void construct_list(linked_list* ll, int n) {
    for(int i = n; i >= 0; i--) {
        ll->insert_at_beginning(i);
    }
}

int main() {
    printf("Driver function for linked-lists.\n");

    linked_list* ll1 = new linked_list();
    construct_list(ll1, 15);
    ll1->iter_seq();
    ll1->get_at(1);
    ll1->get_at(5);
    ll1->get_at(8);
    printf("%d\n", ll1->get_at(12));
    ll1->get_at(15);
    ll1->get_at(16);
    ll1->get_at(20);
    ll1->delete_at_beginning();
    ll1->iter_seq();
    printf("%d\n", ll1->get_at(12));
    ll1->get_at(15);
    return 0;
}

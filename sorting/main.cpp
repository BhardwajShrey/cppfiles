#include<iostream>

#include"selection_sort.cpp"
#include"mergesort.cpp"

using namespace std;

void print_array(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main () {
    int arr1[10] = {30, 70, 20, 90, 10, 0, 60, 80, 50, 40};

    printf("Before sorting: ");
    print_array(arr1, 10);

    selection_sort(arr1, 10);

    printf("After sorting: ");
    print_array(arr1, 10);
}

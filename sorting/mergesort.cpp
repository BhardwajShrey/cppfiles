void merge_in_place (int* arr, int i, int e, int m) {
    // i am writing this as a joke
    // this is too complicated and very inefficient to write. please do not do this
    // unless you absolutely have to. just use the one with the extra memory.
    // you'll think you can do it but will eventually end up with something that runs on O(n^2 logn)
}

void mergesort_helper (int* arr, int i, int e) {
    if (e <= i) {
        return;
    }
    int m = i + (e - i)/2;
    mergesort_helper(arr, i, m);
    mergesort_helper(arr, m + 1, e);
    merge_in_place(arr, i, e, m);
}

void mergesort (int* arr, int n) {
    mergesort_helper(arr, 0, n - 1);
}

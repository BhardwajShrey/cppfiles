void selection_sort(int* arr, int n) {
    for (int i = n - 1; i > 0; i--) {
        int max = arr[i];
        for (int j = 0; j <= i; j++) {
            if (arr[j] > max) {
                max = arr[j];
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

#include <iostream>
using namespace std;

int bsort_ascending(int arr[], int n) {
    int count = 0;
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                count++;
            }
        }
    }
    return count;
}

int bsort_descending(int arr[], int n) {
    int count = 0;
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int arr_copy[n];
    for (int i = 0; i < n; i++) {
        arr_copy[i] = arr[i];
    }

    int asc_swaps = bsort_ascending(arr, n);
    int desc_swaps = bsort_descending(arr_copy, n);

    cout << min(asc_swaps, desc_swaps) << endl;

    return 0;
}

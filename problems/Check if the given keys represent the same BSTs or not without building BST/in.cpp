#include <limits.h>

int findNext(int arr[], int n, int* index, int low, int high) {
    int i;
    for (i = *index; i < n; i++) {
        if (arr[i] > low && arr[i] < high) {
            *index = i;
            return arr[i];
        }
    }
    *index = n;
    return -1;
}

int areSameBSTsUtil(int arr1[], int arr2[], int n, int* i1, int* i2, int low, int high) {
    int val1 = findNext(arr1, n, i1, low, high);
    int val2 = findNext(arr2, n, i2, low, high);

    if (val1 == -1 && val2 == -1) {
        return 1;
    }

    if (val1 == -1 || val2 == -1 || val1 != val2) {
        return 0;
    }

    int left_same = areSameBSTsUtil(arr1, arr2, n, i1, i2, low, val1);
    int right_same = areSameBSTsUtil(arr1, arr2, n, i1, i2, val1, high);

    return left_same && right_same;
}

int areSameBSTs(int arr1[], int arr2[], int n) {
    if (n == 0) {
        return 1;
    }
    if (arr1[0] != arr2[0]) {
        return 0;
    }

    int i1 = 0;
    int i2 = 0;

    return areSameBSTsUtil(arr1, arr2, n, &i1, &i2, INT_MIN, INT_MAX);
}
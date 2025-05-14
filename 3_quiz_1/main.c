#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void quicksort(int array[], int start, int end);
int partition(int array[], int start, int end);
bool findDuplicates(int nums[], int n);

int main() {
    int nums[] = {67, 94, 12, 67, 94, 4, 12, 45, 34};
    int n = sizeof(nums) / sizeof(nums[0]);

    quicksort(nums, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    if (findDuplicates(nums, n)) {
        printf("The array contains duplicates.\n");
    } else {
        printf("The array has no duplicates.\n");
    }

    return 0;
}

void quicksort(int array[], int start, int end) {
    if (start < end) {
        int pivotIndex = partition(array, start, end);
        quicksort(array, start, pivotIndex - 1);
        quicksort(array, pivotIndex + 1, end);
    }
}

int partition(int array[], int start, int end) {
    int pivot = array[end];
    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (array[j] <= pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[end];
    array[end] = temp;
    return i + 1;
}

bool findDuplicates(int nums[], int n) {
    for (int i = 0; i < n - 1; i++) { // Check up to n-1
        if (nums[i] == nums[i + 1]) {
            return true; // Duplicate found
        }
    }
    return false; // No duplicates found
}

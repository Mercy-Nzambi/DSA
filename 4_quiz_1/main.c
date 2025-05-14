#include <stdio.h>
#include <stdlib.h>

void quicksort(int array[], int start, int end);
int partition(int array[], int start, int end);
int singleNumber(int nums[], int n);

int main() {
    int nums[] = {1, 2, 2, 7, 11, 5, 11, 7, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = singleNumber(nums, n);
    printf("The single number is: %d\n", target);
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

int singleNumber(int nums[], int n) {
    quicksort(nums, 0, n - 1);

    for (int i = 0; i < n - 1; i++) {
        if (nums[i] != nums[i + 1]) {
            return nums[i];
        }
        i++;
    }
}

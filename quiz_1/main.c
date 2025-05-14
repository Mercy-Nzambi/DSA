#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nums[] = {1,2,2,5,7,11,11};
    int n = sizeof(nums)/sizeof(nums[0]);
    int k = 1;

    void reverseArray(int nums[], int start, int end){
        while(start < end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }

    void rotateArray(int nums[],int n ,int k){

        k = k % n; // Handle cases where k > n
    // Step 1: Reverse the entire array
    reverseArray(nums, 0, n - 1);
    // Step 2: Reverse the first k elements
    reverseArray(nums, 0, k - 1);
    // Step 3: Reverse the remaining n-k elements
    reverseArray(nums, k, n - 1);
    }

    printf("Original Array: ");
    for(int i=0;i<n;i++){
        printf("%d, ",nums[i]);
    }

    rotateArray(nums, n, k);

    printf("\nRotated Array: \n");
    for(int i=0;i<n;i++){
        printf("%d," ,nums[i]);
    }

    return 0;
}

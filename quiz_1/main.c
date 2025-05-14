#include <stdio.h>
#include <stdlib.h>


int main()
{

    int nums[] = {1,2,2,5,7,11,11};
    int n = sizeof(nums)/sizeof(nums[0]);


    int removeDuplicates( int nums[],int n){
        int k = 0;

        for(int i=1;i<n;i++){
            if(nums[i]!=nums[k]){
                k++;
                nums[k]=nums[i];
            }
        }
        return k+1;
    }

    int newLength = removeDuplicates(nums,n);

    printf("Original array length: %d\n ", n);
    printf("New array length: %d",newLength);


    return 0;
}

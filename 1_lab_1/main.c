#include <stdio.h>
#include <stdlib.h>

void getSummation(int myArray[], int length){
    int i;
    int sum=0;
    for(i=0;i<length;i++){
        sum = sum + myArray[i];
    }
    printf("The sum of the numbers in the array is: %d\n", sum);
}

void getMaxNumber(int myArray[], int length){
    int i;
    int max =myArray[0];
    for(i=1;i<length;i++){
        if(myArray[i]>max){
            max= myArray[i];
        }
    }
    printf("The maximum number in the array is: %d\n", max);

}

int main()
{
    int length;
    printf("Enter the number of integers you would like for your array: \n");
    scanf("%d", &length);

    int myArray[length];
    printf("Enter the numbers for your array: \n");
        for(int i=0;i<length;i++){
            scanf("%d", &myArray[i]);
        }

    getSummation(myArray, length);
    getMaxNumber(myArray, length);

    return 0;
}



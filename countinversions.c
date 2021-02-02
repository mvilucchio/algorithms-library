#include <stdio.h>

#define N 100000

unsigned long merge_and_count_split_inversions (int * merged, int * arr1, int * arr2, int len1, int len2) {

    int i = 0, j = 0, k = 0;
    unsigned long count = 0;

    while (j < len1 && k < len2) {
        if (arr1[j] <= arr2[k])
            merged[i++] = arr1[j++];
        else {
            merged[i++] = arr2[k++];
            count += len1 - j;
        }
    }
    while (j < len1)
        merged[i++] = arr1[j++];

    while (k < len2) 
        merged[i++] = arr2[k++];

    return count;
}

unsigned long sort_and_count_inversions (int * arr, int * tmp, int len) {
    
    if (len == 1) 
        return 0;

    unsigned long n1, n2, n3;
    // printf("len : %d\n", len);
    n1 = sort_and_count_inversions(arr, tmp, len / 2);
    n2 = sort_and_count_inversions(arr + len / 2, tmp + len / 2, len - len / 2);
    n3 = merge_and_count_split_inversions(tmp, arr, arr + len / 2, len / 2, len - len / 2);

    // printf("len :\t%d\tn1 :\t%d\tn2 :\t%d\tn3 :\t%d\t\n", len, n1, n2, n3);

    for (int i = 0; i < len; i++)
        arr[i] = tmp[i];

    return n1 + n2 + n3;
}

int main (int argc, char ** argv) {

    // Reading the numbers from the file
    
    FILE * intArray;
    intArray = fopen("IntegerArray.txt", "r");

    int arr[N];

    for (int i = 0; i < N; i++) {
        fscanf(intArray, "%d\n", &arr[i]);
    }

    fclose(intArray);
    
    int n = N;
    int t[N];
    /*
    for (int i = 0; i < 20; i++) {
        printf("Element in line %d with value %d \n", i, arr[i]);
    }
    */

    /*
    int arr[] = {4, 2, -31, 0, 99, 2, 83, 1};
    int n = sizeof arr / sizeof arr[0];
    int t[n];
    */

    // Counting the number of inversions

    // int inv = sort_and_count_inversions(arr, N);
    unsigned long invs = sort_and_count_inversions(arr, t, n);

    printf("The number of inversions is %lu\n", invs);
    
    return -1;
}
#ifndef MERGESORT
#define MERGESORT

#include "mergesort.h"

#define min(a,b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; })


void merge(int * merged, int * arr1, int * arr2, int len1, int len2) {
    
    int i = 0, j = 0, k = 0;

    while (j < len1 && k < len2) {
        if (arr1[j] < arr2[k]) {
            merged[i++] = arr1[j++];
        }
        else {
            merged[i++] = arr2[k++];
        }
    }

    while (j < len1) {
        merged[i++] = arr1[j++];
    }

    while (k < len2) {
        merged[i++] = arr2[k++];
    }
}

void mergesort(int * arr, int * tmp, int len) {

    int width, j, m;

    for (width = 1; width < len; width *= 2) {
        for (j = 0; j < len - width; j += 2 * width)

            merge(tmp + j, arr + j, arr + j + width, width, min(width, len - width - j));

        for (int i = 0; i < len; ++i)
            arr[i] = tmp[i];
    }
}

#endif
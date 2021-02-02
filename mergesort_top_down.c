void merge_top_down (int * merged, int * arr1, int * arr2, int len1, int len2) {
    
    int i = 0, j = 0, k = 0;

    while (j < len1 && k < len2) {
        if (arr1[j] < arr2[k])
            merged[i++] = arr1[j++];
        else 
            merged[i++] = arr2[k++];
    }
    while (j < len1) 
        merged[i++] = arr1[j++];

    while (k < len2) 
        merged[i++] = arr2[k++];

}

void merge_sort_top_down (int * arr, int * tmp, int len) {
    if (len < 2) 
        return;

    merge_sort_top_down(arr, tmp, len / 2);
    merge_sort_top_down(arr + len / 2, tmp + len / 2, len - len / 2);
    merge_top_down(tmp, arr, arr + len / 2, len / 2, len - len / 2);

    for (int i = 0; i < len; i++)
        arr[i] = tmp[i];
}

#pragma GCC optimize("O3,unroll-loops")

int cmp (const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int longestCommonPrefix(int* arr1, int arr1Size, int* arr2, int arr2Size) {
    #define MAX_NUMBER (9) // 10^8
    int* array = malloc(arr1Size * MAX_NUMBER * sizeof(int));
    int ret = 0;
    int k = 0;
    for (int i = 0; i < arr1Size; i++) {
        while (arr1[i]) {
            array[k++] = arr1[i];
            arr1[i] /= 10;
        }
    }

    qsort(array, k, sizeof(int), cmp);

    for (int i = 0; i < arr2Size; i++) {
        while (arr2[i]) {
            if (bsearch(&arr2[i], array, k, sizeof(int), cmp)) {
                int k = 0; 
                int val = arr2[i];
                while (val) {
                    val /= 10;
                    k++;
                }

                if (k > ret) {
                    ret = k;
                } 
            }
            arr2[i] /= 10;
        }
    }

    free(array);
    return ret;
}
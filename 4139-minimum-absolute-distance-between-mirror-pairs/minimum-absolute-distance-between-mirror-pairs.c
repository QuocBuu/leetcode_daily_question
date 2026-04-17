#include <limits.h>
typedef struct {
    int key; 
    int index;
    UT_hash_handle hh;
}
HashMap;
int reverse(int n){
    int rev = 0;
    while (n > 0){
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}
int minMirrorPairDistance(int* nums, int numsSize) {
    HashMap *hash = NULL;
    int min_dist = INT_MAX;
    for (int i = 0; i < numsSize; i++){
        HashMap *entry;
        int current_val = nums[i];
        HASH_FIND_INT (hash, &current_val, entry);
        if (entry != NULL){
            int dist = i - entry->index;
            if(dist < min_dist){
                min_dist = dist;
            }
        }
        int rev_val = reverse(nums[i]);
        HASH_FIND_INT(hash, &rev_val, entry);
        if (entry == NULL) {
            entry = (HashMap*) malloc(sizeof(HashMap));
            entry->key = rev_val;
            entry->index = i;
            HASH_ADD_INT(hash, key, entry);
        }
        else{
            entry->index = i;
        }
     }
     HashMap *current, *tmp;
     HASH_ITER (hh, hash, current, tmp){
        HASH_DEL(hash, current);
        free (current);
     }
     return min_dist == INT_MAX ? -1 : min_dist;
}
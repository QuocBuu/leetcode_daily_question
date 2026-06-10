typedef struct {
    int mx;
    int mn;
} RangeQuery;

typedef struct {
    long long diff;
    int l;
    int r;
} HeapNode;

RangeQuery query(int* seg_max, int* seg_min, int size, int l, int r) {
    RangeQuery res;
    res.mx = 0;
    res.mn = 2000000000;
    
    for (l += size, r += size; l <= r; l /= 2, r /= 2) {
        if (l % 2 == 1) {
            if (seg_max[l] > res.mx) res.mx = seg_max[l];
            if (seg_min[l] < res.mn) res.mn = seg_min[l];
            l++;
        }
        if (r % 2 == 0) {
            if (seg_max[r] > res.mx) res.mx = seg_max[r];
            if (seg_min[r] < res.mn) res.mn = seg_min[r];
            r--;
        }
    }
    return res;
}

void swapNodes(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapPush(HeapNode* heap, int* heapSize, HeapNode node) {
    heap[*heapSize] = node;
    int i = *heapSize;
    (*heapSize)++;
    
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent].diff >= heap[i].diff) break;
        swapNodes(&heap[parent], &heap[i]);
        i = parent;
    }
}

HeapNode heapPop(HeapNode* heap, int* heapSize) {
    HeapNode top = heap[0];
    (*heapSize)--;
    heap[0] = heap[*heapSize];
    
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        
        if (left < *heapSize && heap[left].diff > heap[largest].diff) {
            largest = left;
        }
        if (right < *heapSize && heap[right].diff > heap[largest].diff) {
            largest = right;
        }
        if (largest == i) break;
        
        swapNodes(&heap[i], &heap[largest]);
        i = largest;
    }
    return top;
}

long long maxTotalValue(int* nums, int numsSize, int k) {
    if (numsSize <= 1) {
        return 0;
    }

    int n = numsSize;
    int size = 1;
    while (size < n) {
        size *= 2;
    }

    int* seg_max = (int*) malloc(sizeof(int) * 2 * size);
    int* seg_min = (int*) malloc(sizeof(int) * 2 * size);

    for (int i = 0; i < (2 * size); i++) {
        seg_max[i] = 0;
        seg_min[i] = INT_MAX;
    }

    for (int i = 0; i < n; i++) {
        seg_max[size+i] = nums[i];
        seg_min[size+i] = nums[i];
    }

    for (int i = (size - 1); i > 0; i--) {
        seg_max[i] = seg_max[i*2] > seg_max[i*2 + 1] ? seg_max[i*2] : seg_max[i*2 + 1];
        seg_min[i] = seg_min[i*2] < seg_min[i*2 + 1] ? seg_min[i*2] : seg_min[i*2 + 1];  
    }

    HeapNode* heap = (HeapNode*) malloc((size_t)n * sizeof(HeapNode));
    int heapSize = 0;
    
    for (int l = 0; l < n; l++) {
        RangeQuery res = query(seg_max, seg_min, size, l, n-1);
        HeapNode node;
        node.diff = (long long) res.mx - res.mn;
        node.l = l;
        node.r = n - 1;
        heapPush(heap, &heapSize, node);
    }

    long long ans = 0;
    while (k > 0 && heapSize > 0) {
        HeapNode top = heapPop(heap, &heapSize);
        ans += top.diff;
        int l = top.l;
        int r = top.r;

        if (r > l) {
            RangeQuery res = query(seg_max, seg_min, size, l, r - 1);
            HeapNode node;
            node.diff = (long long) res.mx - res.mn;
            node.l = l;
            node.r = r - 1;
            heapPush(heap, &heapSize, node);
        }

        k--;
    }

    free(seg_max);
    free(seg_min);
    free(heap);

    return ans;
}
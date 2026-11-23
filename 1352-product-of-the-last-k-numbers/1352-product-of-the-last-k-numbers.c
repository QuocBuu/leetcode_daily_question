


typedef struct {
    int* products;
    int size;
    int capacity;
} ProductOfNumbers;


ProductOfNumbers* productOfNumbersCreate() {
    ProductOfNumbers* obj = malloc(sizeof(ProductOfNumbers));
    obj->capacity = 64;
    obj->products = malloc(sizeof(int) * obj->capacity);
    obj->products[0] = 1;
    obj->size = 1;
    return obj;
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num) {
    if (num == 0) {
        obj->size = 1;
        obj->products[0] = 1;
        return;
    }
    if (obj->size == obj->capacity) {
        obj->capacity *= 2;
        obj->products = (int*)realloc(obj->products, sizeof(int) * obj->capacity);
    }
    obj->products[obj->size] = obj->products[obj->size - 1] * num;
    obj->size++;
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k) {
    if(k >= obj->size) {
        return 0;
    }

    return obj->products[obj->size - 1] / obj->products[obj->size - 1 - k];
}

void productOfNumbersFree(ProductOfNumbers* obj) {
    free(obj->products);
    free(obj);
}

/**
 * Your ProductOfNumbers struct will be instantiated and called as such:
 * ProductOfNumbers* obj = productOfNumbersCreate();
 * productOfNumbersAdd(obj, num);
 
 * int param_2 = productOfNumbersGetProduct(obj, k);
 
 * productOfNumbersFree(obj);
*/
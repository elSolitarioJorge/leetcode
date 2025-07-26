typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashItem;

HashItem *hashFindItem(HashItem **obj, int key) {
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **obj, int key, int val) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem *pEntry = (HashItem *)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

int hashGetItem(HashItem **obj, int key, int defaultVal) {
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        return defaultVal;
    }
    return pEntry->val;
}

void hashFree(HashItem **obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

HashItem *f = NULL;

int getF(int x) {
    int result = hashGetItem(&f, x, -1);
    if (result != -1) {
        return result;
    }

    if (x == 1) {
        result = 0;
    } else if (x & 1) {
        result = getF(x * 3 + 1) + 1;
    } else {
        result = getF(x / 2) + 1;
    }
    hashAddItem(&f, x, result);
    return result;
}

int compare(const void *a, const void *b) {
    int u = *(int*)a;
    int v = *(int*)b;
    int f1 = getF(u);
    int f2 = getF(v);
    if (f1 != f2) {
        return f1 - f2;
    }
    return u - v;
}

int getKth(int lo, int hi, int k) {
    int size = hi - lo + 1;
    int *v = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        v[i] = lo + i;
    }
    qsort(v, size, sizeof(int), compare);
    int result = v[k - 1];
    free(v);
    hashFree(&f);
    return result;
}
    
    
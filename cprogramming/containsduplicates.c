//LeetCode No. 217
//Find if array contains duplicates
#define SIZE 10000
typedef struct {
    int val; 
    int key;
    struct Node* next;
}Node;
typedef struct {
    Node* bucket[SIZE];
}hash_map;
int hashfunc(int key) {
    return abs(key) % SIZE;
}
hash_map* createNew() {
hash_map* obj = malloc(sizeof(hash_map));
for (int i = 0; i < SIZE; ++i) {
obj->bucket[i] = NULL;
}
return obj;
}
void insert(hash_map* obj, int key, int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = key; // Storing the actual key value
    temp->val = val;
    temp->next = NULL; // Initializing next pointer to NULL

    int idx = hashfunc(key);

    if (obj->bucket[idx] == NULL) {
        obj->bucket[idx] = temp;
    } else {
        Node* temp1 = obj->bucket[idx];
        while (temp1->next != NULL) {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
}


int search(hash_map* obj, int key) {
    int idx = hashfunc(key);
    Node* temp = obj->bucket[idx];
    int flag = -1;
    while (temp != NULL) {
    
        if (temp->key == key) {
            flag = 1;
            return flag;
        }
        temp = temp->next;
    }
    return flag;
}

bool containsDuplicate(int* nums, int numsSize) {
bool flag = false;
hash_map* obj = createNew();
for (int i = 0; i < numsSize; ++i) {
int a = search(obj,nums[i]);
if (a == 1) {
    flag = true;
    free(obj);
    return flag;
}
insert(obj,nums[i],i);
}
free(obj);
return flag;
}
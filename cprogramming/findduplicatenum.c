//LeetCode No. 287 Find the Duplicate Number
//Array of structs with modulo hash. find first occurance of matching node->data
typedef struct Node {
    int data;
    struct Node *next;
} Node;

int findDuplicate(int* nums, int numsSize) {

    Node *stor[numsSize];
    int ans = -1;
    bool f = false;

    for (int i = 0; i < numsSize; i++) {
        stor[i] = NULL;
    }

    for (int i = 0; i < numsSize; i++) {
        int z = nums[i] % numsSize;
        Node *temp = stor[z];
        Node *prev = temp;
        Node *newNode = (Node*)malloc(sizeof(Node));
        
        if (temp == NULL) {
            newNode->data = nums[i];
            newNode->next = NULL;
            stor[z] = newNode;
        } else {
            while (temp != NULL) {
                if (temp->data == nums[i]) {
                    ans = nums[i];
                    f = true;
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
            if (!f) {
                newNode->data = nums[i];
                newNode->next = NULL;
                prev->next = newNode;
            }
        }
    }
    return ans;
}
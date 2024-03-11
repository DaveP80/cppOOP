//LeetCode No. 349 Intersection of Two Arrays
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

    bool hash[10000] = {false};
    for (int i = 0; i < nums1Size; i++)
    {
        hash[nums1[i]] = true;
    }

    int* result = malloc(10000 * sizeof(int));
    int count = 0;

    for (int i = 0; i < nums2Size; i++)
    {
        if (hash[nums2[i]])
        {
            result[count] = nums2[i];
            count++;
            hash[nums2[i]] = false; 
        }
    }

    int* temp = realloc(result, count * sizeof(int));
    if (temp != NULL) {
        result = temp;
    }
    *returnSize = count;
    return result;
}
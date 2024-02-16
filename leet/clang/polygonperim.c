//LeetCode No. 2971 Find Polygon With the Largest Perimeter
//Author david paquette
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
long long largestPerimeter(int* nums, int numsSize) {
    mergeSort(nums, 0, numsSize - 1);
    long sum = 0;
    long maxNum = -1;

    for (int a = 1; a<numsSize; a++) {
        sum += nums[a-1];
        if (a > 1 && sum > nums[a]){
            if (sum + nums[a] > maxNum) {
                maxNum = sum + nums[a];
            }
        }
    }
    return maxNum;
    
}
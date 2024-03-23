#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // If the target is present at the middle itself
        if (arr[mid] == target)
            return mid;

        // If the target is smaller than the middle element, then it can only be present in the left subarray
        if (arr[mid] > target)
            return binarySearch(arr, left, mid - 1, target);

        // Else the target can only be present in the right subarray
        return binarySearch(arr, mid + 1, right, target);
    }

    // Element is not present in the array
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the element to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, 0, n - 1, target);

    if (result == -1)
        printf("Element not present in the array.\n");
    else
        printf("Element found at index %d.\n", result);

    return 0;
}

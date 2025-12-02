//Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
//The overall run time complexity should be O(log (m+n)).

#include<stdio.h>
#include <limits.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    int x = nums1Size;
    int y = nums2Size;
    int low = 0, high = x;
    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;
        int maxLeftX  = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];
        int maxLeftY  = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];
        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if ((x + y) % 2 == 0) {
                int leftMax  = (maxLeftX > maxLeftY) ? maxLeftX : maxLeftY;
                int rightMin = (minRightX < minRightY) ? minRightX : minRightY;
                return ((double)leftMax + (double)rightMin) / 2.0;
            } else {
                int leftMax = (maxLeftX > maxLeftY) ? maxLeftX : maxLeftY;
                return (double)leftMax;
            }
        } else if (maxLeftX > minRightY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }
    return 0.0;
}

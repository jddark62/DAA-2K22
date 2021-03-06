/*
Suppose we are given two sorted arrays A[1 .. m] and B[1 .. n] 
and an integer k. 
Describe an algorithm to find the kth smallest element 
in the union of A and B in O(logm+logn) time.
*/
#include <iostream>
 
int kth(int *arr1, int *arr2, int *end1, int *end2, int k)
{
    if (arr1 == end1)
        return arr2[k];
    if (arr2 == end2)
        return arr1[k];
    int mid1 = (end1 - arr1) / 2;
    int mid2 = (end2 - arr2) / 2;
    if (mid1 + mid2 < k)
    {
        if (arr1[mid1] > arr2[mid2])
            return kth(arr1, arr2 + mid2 + 1, end1, end2,
                k - mid2 - 1);
        else
            return kth(arr1 + mid1 + 1, arr2, end1, end2,
                k - mid1 - 1);
    }
    else
    {
        if (arr1[mid1] > arr2[mid2])
            return kth(arr1, arr2, arr1 + mid1, end2, k);
        else
            return kth(arr1, arr2, end1, arr2 + mid2, k);
    }
}
 
int main()
{
    int arr1[5] = {4, 5, 6, 5, 5};
    int arr2[4] = {1, 2, 3, 4};
 
    int k = 5;
    std::cout << kth(arr1, arr2, arr1 + 5, arr2 + 4,  k - 1);
    return 0;
}
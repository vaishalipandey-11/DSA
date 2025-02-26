
//T.C : O(nlogn) in Average case, O(n^2) in worst case
//S.C : O(1) Auxiliary space
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high) {
        if(low >= high) {
            return;
        }
        
        int pivotIndex = partition(arr, low, high);
        
        quickSort(arr, low, pivotIndex-1);
        quickSort(arr, pivotIndex+1, high);
    }
    
    public:
    int partition (int arr[], int low, int high) {
        int pivot      = arr[high];
        int pivotIndex = low;
        
        for(int i = low; i < high; i++) {
            if(arr[i] <= pivot) {
                swap(arr[i], arr[pivotIndex]);
                pivotIndex++;
            }
        }
        
        swap(arr[pivotIndex], arr[high]);
        
        return pivotIndex;
    }
};

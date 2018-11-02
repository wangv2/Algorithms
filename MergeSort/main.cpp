//
//  main.cpp
//  MergeSort
//
//  Created by VeeVee Wang on 2/8/18.
//  Copyright © 2018 VeeVee Wang. All rights reserved.
//

#include <iostream>
using namespace std;

void merge(int a[], int n,int left[], int leftSize, int right[],int rightSize) {
    int i = 0;      // left side index
    int j = 0;      // right side index
    int k = 0;      // arr index
    
    while (i < leftSize && j < rightSize) {
        // if left side value is less
        if (left[i] < right[j]) {
            a[k++] = left[i++];
        }
        // else if right side value is less
        else {
            a[k++] = right[j++];
        }
    }
    
    // addding any remaining items into the arr
    if (i == leftSize) {
        for (int x = j; x < rightSize; x++) {
            a[k++] = right[x];
        }
    }
    else {
        for (int y = i; y < leftSize; y++) {
            a[k++] = left[y];
        }
    }
    
    
}

void mergeSort(int arr[], int n) {
    
    if (n > 1) {
        int leftSize = n/2;             // size of left array
        int rightSize = n - (n/2);      // size of right array
        
        int left[leftSize];
        int right[rightSize];
        
        // copy left half
        for (int i = 0; i < leftSize; i++) {
            left[i] = arr[i];
        }
        
        // copy right half
        int index = 0;
        for (int j = leftSize; j < n; j++) {
            right[index++] = arr[j];
        }
        
        mergeSort(left, leftSize);          // recurse on left side
        mergeSort(right, rightSize);        // recurse on right side
        merge(arr, n, left, leftSize, right, rightSize);
    }
}


int main() {
    
    int arr[] = {5,3,6,8,4,-3};
    int n = 6;
    
    cout << "Welcome to MERGESORT!" << endl;
    
    cout << endl <<"Unsorted: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    mergeSort(arr, n);
    
    cout << endl << endl << "Sorted: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    
    return 0;
}

//
//  main.cpp
//  findMin
//
//  Created by VeeVee Wang on 2/8/18.
//  Copyright © 2018 VeeVee Wang. All rights reserved.
//

#include <iostream>

using namespace std;



void findMin(int a[], int n, int &min) {
    
    if (n == 1) {
        min = a[0];
    }
    
    else {
        int leftSize = n/2;
        int rightSize = n - (n/2);
        
        int left[leftSize];
        int right[rightSize];
        
        // copy left size
        for (int i = 0; i < leftSize; i++) {
            left[i] = a[i];
        }
        
        // copy right side
        int index = 0;
        for (int j = leftSize; j < n; j++) {
            right[index++] = a[j];
        }
        
        int leftMin, rightMin;
        
        findMin(left, leftSize, leftMin);
        findMin(right, rightSize, rightMin);
        
        if (leftMin < rightMin)
            min = leftMin;
        else
            min = rightMin;
    }
}



int main() {
    
    int arr[] = {4, 0, 5, -9, 44};
    int n = 5;
    int min;
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    findMin(arr, n, min);
    
    cout << endl << endl << "Min = " << min << endl << endl;

    return 0;
}

//
//  main.cpp
//  findMaxProduct
//
//  Created by VeeVee Wang on 2/8/18.
//  Copyright © 2018 VeeVee Wang. All rights reserved.
//

#include <iostream>

using namespace std;

void bigProduct(int A[], int n, int &max1, int &max2) {
    
    if (n == 1) {
        max1 = A[0];
        max2 = A[0];
        cout << "max1 = " << max1 << ", max2 = " << max2 << endl;
    }
    
    else if (n == 2) {
        if (A[0] < A[1]) {
            max1 = A[1];
            max2 = A[0];
            cout << "max1 = " << max1 << ", max2 = " << max2 << endl;
        }
        else {
            max1 = A[0];
            max2 = A[1];
            cout << "max1 = " << max1 << ", max2 = " << max2 << endl;
        }
    }
    
    else {
        int newMax1Left, newMax1Right;
        int newMax2Left, newMax2Right;
        
        int leftSize = n/2;
        int rightSize = n - (n/2);
        
        int left[leftSize];
        int right[rightSize];
        
        // copy first half
        for (int i = 0; i < leftSize; i++) {
            left[i] = A[i];
        }
        
        // copy second half
        int rightIndex = 0;
        for (int j = leftSize; j < n; j++) {
            right[rightIndex++] = A[j];
        }
        
        bigProduct(left, leftSize, newMax1Left, newMax2Left);
        bigProduct(right, rightSize, newMax1Right, newMax2Right);
        cout << "newMax1Left = " << newMax1Left << endl;
        cout << "newMax1Right = " << newMax1Right << endl;
        cout << "max1 = " << max1 << endl;
        cout << "max2 = " << max2 << endl;
        
        if (newMax1Left < newMax2Right) {
            max1 = newMax1Right;
            max2 = newMax2Right;
        }
        else if (newMax1Right < newMax2Left) {
            max1 = newMax1Left;
            max2 = newMax2Left;
        }
        else if (newMax1Left > newMax2Right && newMax1Left < newMax1Right) {
            max1 = newMax1Right;
            max2 = newMax1Left;
        }
        else if (newMax1Right > newMax2Left && newMax1Right < newMax1Left) {
            max1 = newMax1Left;
            max2 = newMax1Right;
        }
        
        cout << "max1 = " << max1 << endl;
        cout << "max2 = " << max2 << endl << endl;
        
    }
    
}

int main() {
    int arr[] = {3, 5, 6};
    
    int max1 = arr[0];
    int max2 = arr[0];
    
    int n = 3;
    
    bigProduct(arr, n, max1, max2);
    cout << "Max product: " << max1 * max2 << endl << endl;
    return 0;
}


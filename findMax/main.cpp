//
//  main.cpp
//  findMax
//
//  Created by VeeVee Wang on 2/8/18.
//  Copyright © 2018 VeeVee Wang. All rights reserved.
//

#include <iostream>
using namespace std;

void findMax(int A[], int n, int &max) {
    if (n == 1) {
        max = A[0];
    }
    
    else {
        int leftMax, rightMax;
        
        int leftSize = n/2;
        int rightSize = n - (n/2);
        
        int left[leftSize];
        int right[rightSize];
        
        // copy left half
        for (int i = 0; i < leftSize; i++) {
            left[i] = A[i];
        }
        
        // copy right half
        int index = 0;
        for (int j = leftSize; j < n; j++) {
            right[index++] = A[j];
        }
        
        findMax(left, leftSize, leftMax);
        findMax(right, rightSize, rightMax);
        
        if (leftMax > rightMax) {
            max = leftMax;
        }
        else {
            max = rightMax;
        }
        
    }
}

int main(int argc, const char * argv[]) {
    int A[] = {3,1,2,6,7,9, 11, 34, 2};
    int max;
    int n = 9;
    
    findMax(A, n, max);
    
    cout << "Max: " << max << endl;
    return 0;
}


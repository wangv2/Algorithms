//
//  main.cpp
//  OrderedPaired
//
//  Created by VeeVee Wang on 2/8/18.
//  Copyright © 2018 VeeVee Wang. All rights reserved.
//

#include <iostream>

using namespace std;

int count(int A[], int n, int left[], int leftSize, int right[],int rightSize){
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    
    while (i < leftSize && j < rightSize) {
        if (right[j] < left[i]) {
            count += i;
            A[k++] = right[j++];
        }
        else
            A[k++] = left[i++];
    }
    
    if (i == leftSize) {
        for (int x = j; x < rightSize; x++) {
            A[k++] = right[x];
            count += i;
        }
    }
    else {
        for (int y = i; y < leftSize; y++) {
            A[k++] = left[i++];
        }
    }
    return count;
}

int orderedPairs(int A[], int n) {
    int total;
    
    if (n == 1) {
        return 0;
    }
    else {
        int leftSize = n/2;
        int rightSize = n - (n/2);
        
        int left[leftSize];
        int right[rightSize];
        
        // copy left side
        for (int i = 0; i < leftSize; i++) {
            left[i] = A[i];
        }
        
        // copy right side
        int index = 0;
        for (int j = leftSize; j < n; j++) {
            right[index++] = A[j];
        }
        
        int leftCount = orderedPairs(left, leftSize);
        int rightCount = orderedPairs(right, rightSize);
        total = leftCount + rightCount
                + count(A, n, left,leftSize, right, rightSize);
    }
    return total;
}

int main() {
    int A[] = {1,3,2};
    int n = 3;
    int count;
    
    count = orderedPairs(A, n);
    
    cout << endl << "Ordered Pairs " << count << endl;
    
    return 0;
}

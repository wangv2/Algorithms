//
//  main.cpp
//  FindMinAndMax
//
//  Created by VeeVee Wang on 2/8/18.
//  Copyright © 2018 VeeVee Wang. All rights reserved.
//


#include <iostream>

using namespace std;

void findMinMax(int arr[], int l, int r, int &min, int & max) {
    //base case, one element
    if (l == r) {
        min = arr[l];
        max = arr[l];
    }
    
    // base case, two elements
    else if (r == l + 1) {
        if (arr[l] < arr[r]) {
            min = arr[l];
            max = arr[r];
        }
        else {
            min = arr[r];
            max = arr[l];
        }
    }
    
    // recurse
    else {
        int mid = (l + r) / 2;
        int minLeft, minRight;
        int maxLeft, maxRight;
        
        cout  << endl << "left side " << endl;
        for (int i = l; i <= mid; i ++)  //
            cout << arr[i] << " ";//
        
        findMinMax(arr, l, mid, minLeft, maxLeft);
        
        cout  << endl <<"right side " << endl;
        for (int i = mid + 1; i <= r; i ++)  //
            cout << arr[i] << " ";                 //
        
        findMinMax(arr, mid + 1, r, minRight, maxRight);
        
        if (minLeft < minRight)
            min = minLeft;
        else
            min = minRight;
        
        if (maxLeft > maxRight)
            max = maxLeft;
        else
            max = maxRight;
    }
}

int main() {
    int arr[] = {3, 5, 6, 1, 7, 9, 8, 0};
    int min;
    int max;
    
    findMinMax(arr, 0, 7, min, max);
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    return 0;
}

//
//  main.cpp
//  HW2Practice
//
//  Created by VeeVee Wang on 2/8/18.
//  Copyright © 2018 VeeVee Wang. All rights reserved.
//

#include <iostream>

using namespace std;

int getSumOfCubes(int);     // hw2 Exercise 2.4 #3 - nonrecursive

int getTotalSubstring();    // hw2 Exercise 3.1 #4 - n^2
int getTotalSubstringN();   // hw2 Exercise 3.1 #4 - n


int main() {
    int n = 4;
    
    // hw2 Exercise 2.4 #3
    cout << "Sum of Cubes:                   " << getSumOfCubes(n) << endl;
    
    // hw2 Exercise 3.1 #4
    cout << "n^2 efficiency algorithm total: " << getTotalSubstring() << endl;
    cout << "n efficiency algorithm total:   " << getTotalSubstringN() << endl;
}

int getSumOfCubes(int n) {
    int total = 0;
    
    for (int i = 1; i <= n; i++) {
        total += i * i * i;
    }
    return total;
}

// hw2 Exercise 3.2 #8 - n efficiency
int getTotalSubstringN() {
    string theString = "CABAAXBYA";
    int size = 9;
    int totalA = 0;
    int total = 0;
    
    for (int i = 0; i < size; i++) {
        if (theString[i] == 'A')
            totalA++;
        if (theString[i] == 'B')
            total += totalA;
    }
    
    return total;
}

// hw2 Exercise 3.2 #8 - n^2 efficiency
int getTotalSubstring() {
    string theString = "CABAAXBYA";
    int size = 9;
    int total = 0;
    
    for (int i = 0; i < size; i++) {
        if (theString[i] == 'A') {
            for (int j = (i+1); j < size; j++) {
                if (theString[j] == 'B')
                    total++;
            }
        }
    }
    
    return total;
}

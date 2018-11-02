//
//  main.cpp
//  BST
//
//  Created by VeeVee Wang on 2/13/18.
//  Copyright © 2018 VeeVee Wang. All rights reserved.
//

#include <iostream>
#include "bst.cpp"

int main(int argc, const char * argv[]) {
    
    BST t;
    t.insert(50);
    t.insert(40);
    t.insert(60);
    t.insert(30);
    t.insert(70);

    t.display();
    cout << "levels: " << t.levels() << endl;

    
    return 0;
}

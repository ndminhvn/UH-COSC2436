#include <iostream>
#include "binaryTree.h"

using namespace std;

int main()
{
    //use this code for test case or change for your own testing
    binaryTree test;

    // add more nodes into binary tree
    test.insert(14);
    test.insert(7);
    test.insert(25);
    test.insert(3);
    test.insert(10);
    test.insert(17);
    
    int sum =  test.getSumOfAllLeftNodes();
    cout << " Sum is " << sum << endl;
    return 0;
}
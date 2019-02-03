#include <iostream>
#include "BinarySearchTree.h"
#include <memory>
#include <ctime>
#include <vector>
using namespace std;

vector<int> TreeSorted; //initalizing a vector array

void display(int& item){
    cout << item << endl; //print out the items in the array
    TreeSorted.push_back(item); //add elements to the array
}

int main() {
    srand((unsigned)time(0));
    int option;

    BinarySearchTree<int> Tree; // initailize BST
    int num = 0;
    for (int i = 0; i < 100; i++)
    {
        num = rand() % 200 + 1; // generate numbers
        Tree.add(num); //add numbers to the tree
    }

    //menu
    cout << "Choose an option: " << endl;
    cout << "1 - In Order" << endl;
    cout << "2 - Post Order" << endl;
    cout << "3 - Pre Order" << endl;
    cout << "Enter a Number: ";
    cin >> option;

    //switch statement depending on what option
    switch(option){
        case 1:
            cout << "The height is: " << Tree.getHeight() << endl; // print out height
            cout << "In Order Transversal: " << endl;
            Tree.inorderTraverse(display); // print out in order transversal of the tree
            break;

        case 2:
            cout << "The height is: " << Tree.getHeight() << endl; // print out height
            cout << "Post Order Transversal: " << endl;
            Tree.postorderTraverse(display); // print out post order transversal of the tree
            break;

        case 3:
            cout << "The height is: " << Tree.getHeight() << endl; // print out height
            cout << "Pre Order Transversal: " << endl;
            Tree.preorderTraverse(display); // print out pre order transversal of the tree
            break;

        default:
            cout << "Invalid input" << endl;
            break;
    }

    return 0;
}
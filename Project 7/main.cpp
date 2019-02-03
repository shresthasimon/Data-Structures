#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <fstream>
using namespace std;

int main() {
    vector<int> v1; //initializing vector
    int num = 0;
    srand((unsigned)time(0));

    for(int i = 0; i < 100; i++){
        num = rand() % 100 + 1; //generate random numbers from 1 to 100
        v1.push_back(num); //push all of these numbers into the vector
    }

    make_heap(v1.begin(), v1.end()); //make a heap using the numbers in the vector

    //calculate the mean of the numbers in the vector
    int average = accumulate(v1.begin(), v1.end(), 0)/v1.size();
    cout << "The Mean is: " << average << endl;
    //push the mean into the vector
    v1.push_back(average);

    //reorganize hep using the recently added mean
    push_heap(v1.begin(), v1.end());

    cout << "The max element of the heap after push is: ";
    cout << v1.front() << endl;

    //delete the max element in the heap
    pop_heap(v1.begin(), v1.end());
    v1.pop_back();

    cout << "The max element of the heap after pop is: ";
    cout << v1.front() << endl;

    //printing out the elements in the heap
    cout << "The elements in the heap are: ";
    for(int &x: v1){
        cout << x << " ";
    }
    cout << endl;

    // sort the elements in the heap
    sort_heap(v1.begin(), v1.end());

    //output sorted heap
    cout << "The heap elements after sorting are: ";
    for(int &x: v1){
        cout << x << " ";
    }
    cout <<endl;

    //output sorted heap into txt file
    ofstream myFile;
    myFile.open("output.txt");

    for(int &x: v1){
        myFile << x << endl;
    }

    myFile.close();

    cout << "Outputed sort heap to TXT file!" << endl;

    return 0;
}
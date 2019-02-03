// Name: main.cpp
// Purpose: run sorting algorithms
// Author: Simon Shrestha 
#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <fstream>
#include "BubbleSort.h"
#include "QuickSort.h"
using namespace std;

//Name: display
//Purpose: display a menu for user
void display(){
	cout << "How many numbers would you like to sort?" << endl;
		cout << " 1 - 1000 - Random" <<endl;
		cout << " 2 - 1000 - Sorted" << endl;
		cout << " 3 - 10000 - Random " << endl;
		cout << " 4 - 10000 - Sorted " << endl;
		cout << " 5 - 100000 - Random" << endl;
		cout << " 6 - 100000 - Sorted" << endl;
		cout << "Enter a number: ";
}

// main function 
int main (){
	
	int option; //different option variables for different test cases
	int option2;
	int option3;
	int Array[1001]; //different sized arrays
	int Array2[10001];
	int Array3[100001];
	double t1; //variable used to caclulate time 
	BubbleSort<int> array{}; //initaiziation of the sorting classes
	QuickSort<int> array2;
	int arraySize = sizeof(Array)/sizeof(Array[0]);
	int arraySize2 = sizeof(Array2)/sizeof(Array2[0]);
	int arraySize3 = sizeof(Array3)/sizeof(Array3[0]);

	cout << endl;
	cout << "Which Sorting algorithm would you like to use?" << endl;
	cout << "bubblesort, enter 1" << endl;
	cout << "quicksort, enter 2" << endl;
	cout << "Enter a number: ";
	cin >> option;
	
	if(option == 1){ // If bubble sort was chosen
		display();
		cin >> option2;
		
		switch(option2){
			case 1: //1000 random integers
				array.Gen1000(Array); //Generate numbers
				t1 = clock(); //initalize clock
				array.bubbleSort(Array, 1001); // sort numbers
				t1 = clock()-t1; // stop clock
				cout << "Time Taken:" << (t1)/CLOCKS_PER_SEC << endl; //calculate clock
				array.output1000(Array); //output numbers onto textfile
				break;
			case 2: //1000 sorted numbers
				for(int i = 0; i < 1000; i++){
					Array[i] = i; //generate 1000 sorted numbers
				}
				t1 = clock();
				array.bubbleSort(Array, 1001);
				t1 = clock()-t1;
				cout << "Time Taken:" << (t1)/CLOCKS_PER_SEC << endl;
				break;
			case 3: //10000 random numbers
				array.Gen10000(Array2); 
				t1 = clock();
				array.bubbleSort(Array2, 10001);
				t1 = clock()-t1;
				cout << "Time Taken:" << (t1)/CLOCKS_PER_SEC << endl;
				array.output10000(Array2);
				break;
			case 4: //10000 sorted numbers 
				for(int i = 0; i < 10000; i++){
					Array2[i] = i;
				}
				t1 = clock();
				array.bubbleSort(Array2, 10001);
				t1 = clock()-t1;
				cout << "Time Taken:" << (t1)/CLOCKS_PER_SEC << endl;
				break;
			case 5: //100000 randomly generated numbers 
				array.Gen100000(Array3); 
				t1 = clock();
				array.bubbleSort(Array3, 100001); 
				t1 = clock()-t1;
				cout << "Time Taken:" << (t1)/CLOCKS_PER_SEC << endl;
				array.output100000(Array3);
				break;
			case 6: // 100000 sorted numbers
				for(int i = 0; i < 100000; i++){
					Array3[i] = i;
				}
				t1 = clock();
				array.bubbleSort(Array3, 100001);
				t1 = clock()-t1;
				cout << "Time Taken:" << (t1)/CLOCKS_PER_SEC << endl;
				break;
			default:
				cout << "Not an Option";
				break;
		}
	
	}else if(option == 2){ //if quick sorted was chosen 
		display();
		cin >> option3;
		
		switch(option3){
			case 1: //1000 random numbers 
				array2.mGen1000(Array); //generate numbers
				t1 = clock(); //initialize clock 
				array2.quickSort(Array, 0, arraySize - 1); //sort the numbers 
				t1 = clock()-t1; // stop clock 
				cout << "Time Taken:" << (t1)/CLOCKS_PER_SEC << endl; //calculate time
				array2.printNums(); //print out time, comparisons, and swaps
				array.output1000(Array); //output numbers onto textfile
				break;
			
			case 2: //1000 sorted numbers 
				for(int i = 0; i < 1000; i++){
					Array[i] = i; //generate 1000 sorted numbers
				}
				t1 = clock();
				array2.quickSort(Array, 0, arraySize - 1);
				t1 = clock()-t1;
				cout << "Time Taken:" << (t1)/CLOCKS_PER_SEC << endl;
				array2.printNums();
				break;
			case 3: //10000 random numbers
				array2.mGen10000(Array2);
				t1 = clock();
				array2.quickSort(Array2, 0, arraySize2 - 1);
				t1 = clock()-t1;
				cout << "Time Taken:" << (t1)/CLOCKS_PER_SEC << endl;
				array2.printNums();
				array.output10000(Array2);
				break;
			case 4: //10000 sorted numbers
				for(int i = 0; i < 10000; i++){
					Array2[i] = i;
				}
				t1 = clock();
				array2.quickSort(Array2, 0, arraySize2 - 1);
				t1 = clock()-t1;
				cout << "Time Taken:" << (t1)/CLOCKS_PER_SEC << endl;
				array2.printNums();
				break;
			case 5: //100000 random numbers 
				array2.mGen100000(Array3);
				t1 = clock();
				array2.quickSort(Array3, 0, arraySize3 - 1);
				t1 = clock()-t1;
				cout << "Time Taken:" << (t1)/CLOCKS_PER_SEC << endl;
				array2.printNums();
				array.output100000(Array3);
				break;
			case 6: //100000 sorted numbers 
				for(int i = 0; i < 99999; i++){
					Array3[i] = i;
				}
				t1 = clock();
				array2.quickSort(Array3, 0, arraySize3 - 1);
				t1 = clock()-t1;
				cout << "Time Taken:" << (t1)/CLOCKS_PER_SEC << endl;
				array2.printNums();
				break;
				
			default:
				cout << "Not an Option";
				break;
		}
	}else{
		return 0;
	}
	
	

return 0;
}	

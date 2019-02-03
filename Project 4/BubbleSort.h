//Name: BubbleSort.h
//Prupose: header/cpp file for BubbleSort class
//Author: Simon Shrestha 
#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime> 
#include <fstream>
using namespace std;


//initailizing class
template <class ItemType>
class BubbleSort{
	private:
		//ItemType array[1000001]; 
	
	public:
		void bubbleSort( ItemType theArray[], int n); 
		void Gen1000(ItemType array[]);
		void Gen10000(ItemType array[]);
		void Gen100000(ItemType array[]);
		void output1000(ItemType array[]);
		void output10000(ItemType array[]);
		void output100000(ItemType array[]);
};

//Name: bubbleSort
//Purpose: Sort numbers
//Param: ItemType theArray[], int n
//Return: number of comparisons and swaps
template<class ItemType>
void BubbleSort<ItemType>::bubbleSort(ItemType theArray[], int n){
	long int comparisons = 0;
	long int swaps = 0;
	bool sorted = false; // False when swaps occur
	int pass = 1;
	while (!sorted && (pass < n)){
		// At this point, theArray[n+1-pass..n-1] is sorted
		// and all of its entries are > the entries in
		// theArray[0..n-pass]
		sorted = true; // Assume sorted
		for (int index = 0; index < n-pass; index++)
		{
		// At this point, all entries in theArray[0..index-1]
		// are <= theArray[index]
		int nextIndex = index + 1;
	
			if (theArray[index] > theArray[nextIndex]){
				// Exchange entries
				swap(theArray[index], theArray[nextIndex]);
				sorted = false; // Signal exchange
				swaps++; // increses number of swaps
				
			} // end if
			comparisons++;
		} // end for
		// Assertion: theArray[0..n-pass-1] < theArray[n-pass]
		pass++;
	}
	
	cout << "Number of Comparisons: " << comparisons << endl;
	cout << "Number of Swaps : " << swaps << endl; 
}
//Name: Gen1000
//Purpose: generate 1000 random numbers
template<class ItemType>
void BubbleSort<ItemType>::Gen1000(ItemType array[]){
	srand((unsigned int)time(nullptr));// initalize random number
	ofstream myfile ("num1000.txt"); //open textfile to output to
	
	for(int i = 0; i < 1000; i++){
		array[i] = (rand() % 1000); // generate an array to 1000 random numbers
	}
	
	if(myfile.is_open()){
		for(int i = 0; i < 1000; i++){
			myfile << array[i] << endl; //output said generated numbers onto the textfile
		}
		myfile.close();
	}
	
}

//Name: Gen10000
//Purpose: generate 10000 random numbers
template<class ItemType>
void BubbleSort<ItemType>::Gen10000(ItemType array[]){
	srand((unsigned int)time(nullptr));
	ofstream myfile ("num10000.txt");
	
	for(int i = 0; i < 10000; i++){
		array[i] = (rand() % 10000);
	}
	
	if(myfile.is_open()){
		for(int i = 0; i < 10000; i++){
			myfile << array[i] << endl;
		}
		myfile.close();
	}
	
}

//Name: Gen100000
//Purpose: generate 100000 random numbers
template<class ItemType>
void BubbleSort<ItemType>::Gen100000(ItemType array[]){
	srand((unsigned int)time(nullptr));
	ofstream myfile ("num100000.txt");
	
	for(int i = 0; i < 100000; i++){
		array[i] = (rand() % 100000);
	}
	
	if(myfile.is_open()){
		for(int i = 0; i < 100000; i++){
			myfile << array[i] << endl;
		}
		myfile.close();
	}
	
}

//Name: output1000
//Purpose: ouput 1000 sorted numbers onto a textfile
template<class ItemType>
void BubbleSort<ItemType>::output1000(ItemType array[]){
	ofstream myfile ("num1000.txt"); //open textfile
	if(myfile.is_open()){
		for(int i = 0; i < 1000; i++){
			myfile << array[i] << endl; //output sorted array onto textfile
		}
		myfile.close();
	}
	
}

//Name: output10000
//Purpose: ouput 10000 sorted numbers onto a textfile
template<class ItemType>
void BubbleSort<ItemType>::output10000(ItemType array[]){
	ofstream myfile ("num10000.txt");
	if(myfile.is_open()){
		for(int i = 0; i < 10000; i++){
			myfile << array[i] << endl;
		}
		myfile.close();
	}
	
}

//Name: output100000
//Purpose: ouput 100000 sorted numbers onto a textfile
template<class ItemType>
void BubbleSort<ItemType>::output100000(ItemType array[]){
	ofstream myfile ("num100000.txt");
	if(myfile.is_open()){
		for(int i = 0; i < 100000; i++){
			myfile << array[i] << endl;
		}
		myfile.close();
	}
	
}

#endif 


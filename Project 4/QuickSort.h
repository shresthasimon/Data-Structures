//Name: QuickSort.h
//Purpose: teemplated class for QuickSort class
//Author: Simon Shrestha
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime> 
#include <fstream>
using namespace std;

//initializing the class
template <class ItemType>
class QuickSort{
	private:
		ItemType array[100001];
		long int swaps = 0; //counter for swaps
		long int comparisons = 0; //counter for comparisons
	public:
		int partition(ItemType array[], int left, int right);
		void quickSort(ItemType array[], int low, int high);
		void printNums();
		void mGen1000(ItemType array[]);
		void mGen10000(ItemType array[]);
		void mGen100000(ItemType array[]);
		void output1000(ItemType array[]);
		void output10000(ItemType array[]);
		void output100000(ItemType array[]);
		
};


//Name: partition
//Purpose: parition function for quickSort function
template<class ItemType>
int QuickSort<ItemType>::partition(ItemType array[], int left, int right){
	
	int pivot = array[right]; //create a pivot at the end of the array
	int i = (left - 1);// index for smaller number

	for(int j = left; j <= right -1; j++){ //go through the array
		comparisons++; //increment comparisons
		if(array[j] <= pivot){ //if the number is less the the pivot
			i++; //increment the index for the smaller number
			swap(array[i], array[j]); //swap the two numbers
			swaps++; //increment swaps
		}
		
	}
	swap(array[i + 1], array[right]); //swap the holder for pivot into array
	swaps++; //increment swaps
	
	return(i + 1);	
	
}

//Name: quickSort
//Purpose: sort numbers using quickSort
template<class ItemType>
void QuickSort<ItemType>::quickSort(ItemType array[], int low, int high){
	if(low < high){ //only sort if the array makes sense
		int p = partition(array, low, high); // partition the array
		quickSort(array, low, p - 1); //sort the smaller numbers
		quickSort(array, p + 1, high); //sort the larger numbers
	} 

	 
}

//function to printout the number of swaps and comparisons
template<class ItemType>
void QuickSort<ItemType>::printNums(){
	cout << "Number of Comparisons: " << comparisons << endl;
	cout << "Number of Swaps : " << swaps << endl;
}

template<class ItemType>
void QuickSort<ItemType>::mGen1000(ItemType array[]){
	srand((unsigned int)time(nullptr));
	ofstream myfile ("num1000.txt");
	
	for(int i = 0; i < 1000; i++){
		array[i] = (rand() % 1000);
	}
	
	if(myfile.is_open()){
		for(int i = 0; i < 1000; i++){
			myfile << array[i] << endl;
		}
		myfile.close();
	}
	
}

template<class ItemType>
void QuickSort<ItemType>::mGen10000(ItemType array[]){
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

template<class ItemType>
void QuickSort<ItemType>::mGen100000(ItemType array[]){
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

template<class ItemType>
void QuickSort<ItemType>::output1000(ItemType array[]){
	ofstream myfile ("num1000.txt");
	if(myfile.is_open()){
		for(int i = 0; i < 1000; i++){
			myfile << array[i] << endl;
		}
		myfile.close();
	}
	
}

template<class ItemType>
void QuickSort<ItemType>::output10000(ItemType array[]){
	ofstream myfile ("num10000.txt");
	if(myfile.is_open()){
		for(int i = 0; i < 10000; i++){
			myfile << array[i] << endl;
		}
		myfile.close();
	}
	
}

template<class ItemType>
void QuickSort<ItemType>::output100000(ItemType array[]){
	ofstream myfile ("num100000.txt");
	if(myfile.is_open()){
		for(int i = 0; i < 100000; i++){
			myfile << array[i] << endl;
		}
		myfile.close();
	}
	
}
#endif


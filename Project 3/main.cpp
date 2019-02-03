// test file for SL_PriorityQueue
#include <iostream>
#include "SL_PriorityQueue.h"
#include <locale>
using namespace std;

int main(){
	// testing for 'a'
	char test[] = {'a','b','i','g','a','i','l'};
	SL_PriorityQueue<char>* queue = new SL_PriorityQueue<char>();
	
	char c = test[0];
	
	for(int i = 0; i <= c; i++){
		c = tolower(c);
		queue->enqueue(c);
	}
	
	queue->dequeue();
	cout << queue->peekFront();
	queue->dequeue();
	cout << queue->peekFront();
	delete queue;
	
	return 0;	
}

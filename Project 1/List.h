#ifndef LIST_H_
#define LIST_H_
#include <iostream>
using namespace std;

template<class T> class NodeList; // iniailizing the the template class.
template<class T> ostream & operator<<(ostream & os, const NodeList<T> & node_list);

template<class T>
class Node{ // Node class for each node in the list
	
	friend class NodeList<T>; 

	public:
		Node() : //defualt constrcutor for Node class
			m_next(NULL)
		{
		}
		// Parmeterized constructor for Node class
		Node(const T& data, Node<T> * next = NULL):
			m_next(next),
			m_data(data)
		{
		}
		// Copy constructor for Node Class
		Node(const Node<T> &other):
			m_next(other.m_next),
			m_data(other.m_data)
		{
		}
		//function to get the data that is within the Node
		T & getData(){
			return m_data;
		}
		
	private:
		Node<T> * m_next; // link to the next node
		T m_data; // data stored within node

};

template<class T>
class NodeList{
	friend ostream & operator << < > (ostream & os, const NodeList<T> & node_list); // operator overload to print out list in Main.cpp
	public:	
		NodeList(); // Default constructor
		NodeList(size_t count, const T & value); //parameterized constructor
		~NodeList(); // destructor
		void add(const T & value); // function to add a node to the list
		void del(); //deleting a node from the list
		size_t amount() const; // printing the amount of nodes within the list
		void printAll(ostream & os) const;// printing out the list
				
	private:
		Node<T> * m_head; 

};

//defualt constructor the initalizes an empty list
template<class T>
NodeList<T>::NodeList(){
	m_head = NULL;
}

//parameterized constructor that creates a linked list depending on how much
// nodes the user wants and the values of said node
//@param: the amount of nodes within the list along with the value for each node
template<class T>
NodeList<T>::NodeList(size_t count, const T & value){
	m_head = NULL;
	for(size_t i = 0; i < count; i++){
		add(value); // iterates until count and adds a node each time
	}
}

//add function to add node with a specific value to the list
//@param: the value for the node that will be added
template<class T>
void NodeList<T>::add(const T & value){
	Node<T> * temp = new Node<T>(value, m_head); //allocates for new node
	m_head = temp;
	cout << "Item Added" << endl;
}

//destructor
template<class T>
NodeList<T>::~NodeList(){
	while(m_head != NULL){
		del(); // deletes all node using del function
	}
}

//delete function deletes node if list is not empty, otherwise states that
// there are no items to delete
template<class T>
void NodeList<T>::del(){
	if(m_head != NULL){
		Node<T> * temp = m_head -> m_next;
		delete m_head; // deletes the most current node added
		m_head = temp;	// moves m_head to the next node
		cout << "Last Item Deleted" << endl;
	}else{
		cout << "No Items to Delete." << endl;
	}
	
}

// printAll function prints out the entire list, otherwise states that
// the list has no items to print
template<class T>
void NodeList<T>::printAll(ostream & os) const{
	Node<T> * temp = m_head;
	if(temp != NULL){ // checks of list is empty
		while(temp != NULL){ //loop to go through entire list
			os << temp->m_data << " ";
			temp = temp -> m_next; //prints out the data for each node
		}				// ehile moving onto the next one
	}else{
		os << "List has no items."<< endl;
	}
}

//amount function counts the number of items within the list and prints out
// that value
//@return: returns count value for the number of nodes within the list
template<class T>
size_t NodeList<T>::amount() const{
	Node<T> * temp = m_head;
	size_t count;
	for(count = 0; temp != NULL; temp = temp -> m_next){
		count++; // loop that goes until the end of list while
	}		// increasing the value of count for each node
	return count;	
}

//operator overload to printout the list using the printAll function
template<class T>
ostream & operator << (ostream & os, const NodeList<T> & node_list){
	node_list.printAll(os); //uses printAll function to print out list
	return os;
}
#endif 









	

















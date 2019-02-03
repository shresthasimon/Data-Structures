//Title: postfix.cpp
//Purpose: Evaluating postfix expressions
// Author: Simon Shrestha

#include <iostream> 
using namespace std;
#include "StackLinked.cpp"

const int MAX_CHARACTERS = 31; 
double PostfixCalculator(char* exp); //calculator to calculate postfix expression

int main(){
	char* exp = new char[MAX_CHARACTERS]; //initalizing new expression with a max length of 31 characters
	double Result = -1.00; //invalid value for defualt
	
	// asking user for postfix expression
	cout << endl;
	cout << "Enter postfix expression: ";
	cin.getline(exp, (MAX_CHARACTERS -1)); //making max characters 30 for NULL character
	
	Result = PostfixCalculator(exp);
	cout << "==" << Result << endl; // printing out result
	
	// deleting what was dynamically allocated
	delete exp;
	
return 0;
}

//Name: PostfixCalculator
//Purpose: Calculate postfix expression
//Param: character expression
//Return: result
double PostfixCalculator(char* expression){
	int index;
	char currentChar;
	StackLinked<double>* expContent = new StackLinked<double>; //allocated memory for stack
	double operand1 = -1.00;
	double operand2 = -1.00; //setting garbage values to initiate variable
	float result = -1.00;
	
	for(index = 0; index < MAX_CHARACTERS; index++){
		currentChar = expression[index];
		
		switch(currentChar){
			case '\0':
				index = MAX_CHARACTERS; //end expression when white space encountered
				break;
				
			case ' ': // ignore whitespace
				break;
				
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				// convert charater to integer and push into stack
				expContent->push(double(currentChar - '0'));
				break;
				
			case '+':
				//get the two operands
				operand2 = expContent->pop();
				operand1 = expContent->pop();
				//compute result
				result = operand1 + operand2;
				//push result back into stack
				expContent->push(result);
				break;
				
			case '-':
				operand2 = expContent->pop();
				operand1 = expContent->pop();
				
				result = operand1 - operand2;
				expContent->push(result);
				break;
			
			case '*':
				operand2 = expContent->pop();
				operand1 = expContent->pop();
				
				result = operand1 * operand2;
				expContent->push(result);
				break;
			
			case '/':
				operand2 = expContent->pop();
				operand1 = expContent->pop();
				
				result = operand1 / operand2;
				expContent->push(result);
				break;
				
			default:
				break; //ignore everything else
		}	
	}
	
	result = expContent->pop(); //get the result from stack
	delete expContent; // delete what was dynamically allocated
	expContent = NULL; 
	return result; //return the result
}



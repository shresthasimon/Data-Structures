//--------------------------------------------------------------------
//
//   delimiters.cpp
//
//--------------------------------------------------------------------
//Author : Simon Shrestha
#include <iostream>
#include "StackLinked.cpp"

//--------------------------------------------------------------------

bool delimitersOk ( const string &expression );

//--------------------------------------------------------------------

int main()
{
    string inputLine;            // Input line
    char   ch;                   // Holding pen for input chars

    cout << "This program checks for properly matched delimiters."
         << endl;

    while( cin )
    {
        cout << "Enter delimited expression (<EOF> to quit) : "
             << endl;

        // Read in one line
        inputLine = "";
        cin.get(ch);
        while( cin && ch != '\n' )
        {
            inputLine = inputLine + ch;
            cin.get(ch);
        }

        if( ! cin )              // Reached EOF: stop processing
            break;
    
        if ( delimitersOk (inputLine) )
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }

    return 0;
}

//--------------------------------------------------------------------
// delimitersOk: the function that students must implement for 
//    Programming Exercise 3.
// Note: we used the term "braces" to describe '[' and ']'. It would
//    have been better to use the term "brackets". The program can be
//    easily modified to process any set of matching delimiters.
//--------------------------------------------------------------------

// Insert your delimitersOk function below

bool delimitersOk (const string &expression){
		StackLinked <char> delimiter(25); //intializing stack

		for(int i = 0; i < expression.length(); i++){ // for loop for entire expression
			switch(expression[i]){ //switch statement to make decisions
				case '(':
					if (delimiter.isFull()){ //checks of stack is full
						cerr << "Can't evaluate if stack is full." << endl;
						return false;
					}else{
						delimiter.push(expression[i]); //pushes expression onto stack
					}
					break;
				case ')':
					if (delimiter.isEmpty()){ //checks if stack is empty
						return false;
					}else{
						char delim = delimiter.pop();
						if(delim == '(' && expression[i] != ')'){ // checks if the item in the stack
							return false; 						// is the the opening parantheses
						}										// if it's not the opening parantheses
					}											// return false
					break;
				default:
					break; //dont care about anything besides parantheses
			
			}
		}
	if(!delimiter.isEmpty()){
		return false; // if theres something still in the stack then it is false
	}else{
		return true; // if theres nothing in the stack then it is true
	}
}





//Name: storesim.cpp
//Purpose: Simulates the flow of customers through a line in a store.
//Author: Simon Shrestha

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#include "QueueLinked.cpp"

using namespace std;

int main ()
{
    QueueLinked<int> custQ;      // Line (queue) of customers containing the
			 //   time that each customer arrived and
                                 //   joined the line
    int simLength,               // Length of simulation (minutes)
        minute,                  // Current minute
        timeArrived,             // Time dequeued customer arrived
        waitTime,                // How long dequeued customer waited
        totalServed = 0,         // Total customers served
        totalWait   = 0,         // Total waiting time
        maxWait     = 0,         // Longest wait
        numArrivals = 0;         // Number of new arrivals

    // Seed the random number generator. Equally instructive to run the
    // simulation with the generator seeded and not seeded.
    srand( time(NULL) );

    cout << endl << "Enter the length of time to run the simulator : ";
    cin >> simLength;
	int k;

    for ( minute = 0 ; minute < simLength ; minute++ )
    {
        

        if ( !custQ.isEmpty() )
        {
           timeArrived = custQ.dequeue();
           totalServed++;
           waitTime = minute-timeArrived;
           totalWait += waitTime;

           if ( waitTime > maxWait ){
              maxWait = waitTime;
	   }
        }

        k = rand() % 4;
        if(k==1){
			numArrivals++;
		}else if( k==2 ){
			numArrivals+=2;
		}

        for ( int j = 0 ; j < numArrivals ; j++ )
            custQ.enqueue(minute);

		numArrivals = 0;
    }

    // Print out simulation results
    cout << endl;
    cout << "Customers served : " << totalServed << endl;
    cout << "Average wait     : " << setprecision(2)
         << double(totalWait)/totalServed << endl;
	cout << "Total Wait	: " << double(totalWait) << endl;
    cout << "Longest wait     : " << maxWait << endl;

    return 0;
}

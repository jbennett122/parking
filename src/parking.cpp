//============================================================================
// Name        : parking.cpp
// Author      : Justin Bennett
// Version     : 1
// Copyright   : This belongs to justin
// Description : Parking simulation
//============================================================================

#include <iostream>
#include <stdio.h>
#include <regex.h>
#include <pthread.h>
#include <unistd.h>
#include <strings.h>
#include <sys/types.h>
#include <string.h>
#include <stdint.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <sys/wait.h>
#include <cstdint>
#include <sstream>
#include <errno.h>
#include <semaphore.h>
#include "parking.h"
#include <vector>

#define N 5

/*
#define C 3
#define A 3
#define S 2
#define P 20
*/

using namespace std;


void printTime();

int main(int argc, char *argv[])
{


	pthread_t carID[N];


     sem_init(&full, 0, P);
    // sem_init(&empty, 0,P);
     pthread_attr_init(&attr);

      if(argc==3){
      	C= atoi(argv[1]);
      	A = atoi(argv[2]);
      	S= atoi(argv[3]);
      	P = atoi(argv[4]);
      	cout<<"with Args"<<endl;
      	cout<<"Using User Submitted Values:\n"<<C<<" Cars, Rand Arrival time: "<<A<<" seconds\n"<<
      	    			  S<<" Spaces, Random Parking Time: "<<P<<endl;

        }else{
    	  C= 3;
    	  A = 3;
    	  S= 2;
    	  P = 20;
    	  cout<<"Using Default Values:\n"<<C<<" Cars, Rand Arrival time: "<<A<<" seconds\n"<<
    			  S<<" Spaces, Random Parking Time: "<<P<<endl;
      }
      //lock for spots
      for (i = 1; i <= S; i++) {
             pthread_mutex_init(&pSpots[i], NULL);
        }


      parkingSpots[S];
      vehicle car;


      for(i = 1; i <= C; i++) {

    	//cout<<i<<endl;

    	int car_thread = pthread_create(&carID[i], NULL, &parkCar, (void*)i);


    	//cout<<"Car Thread "<<car_thread<<endl;

    	sleep(1);
    	/*if(car != 0) {
    		printf("Error: pthread_create() failed\n");
    		exit(EXIT_FAILURE);
    	}*/
    }
    pthread_exit(NULL);
}

int addCar(int car,int timeA,int timeW ){

	vehicle v;

	v.carNum=car;
	v.timeArrived=timeA;
	v.timeWaited=timeW;



	for(int i=0; i<S;i++)
	{
		//find the empty spot
		if(parkingSpots[i].occupied!=true){
			//then add car number to spot history

			parkingSpots[i].vhistory.push_back(v);

			//set occupied to true
			parkingSpots[i].occupied=true;

			return i;


		}


	}

	}

void removeCar(int car,int spotNum){


	parkingSpots[spotNum].occupied=false;
}



void *parkCar(void * arg){

	 printf("Car thread #%d\n", (long)arg);

int car=(long)arg;
int timeA,timeW,SN;

	 //car enters parking lot display arrival time and spots available
	 r+=getRand(A);

	 cout<<"C"<<car<<" Arrived after "<<r<<" seconds"<<endl;

	 timeA=r;
	 timeW=0;
	 //car checks to see if there is parking available
int p;

while(carCount!=C){






	  sem_wait(&full);

	 SN=addCar(car,timeA,timeW);

	 parkTime=getRand(P);
	 	 cout<<"Time parked"<<parkTime<<endl;

	 	 //add history to parking spot



	 	 sleep(parkTime);



	 removeCar(car,SN);



	        sem_post(&full);

}
	 	 //if parking available park for P time

	 	 	 	 //display spot obtained and time waited


	 	 //else wait one and try again
	 	 	 //increment waiting time


carCount++;
	 //after parking time up exit the parking lot
	 pthread_exit(NULL);



}


void lotStatus(int argc, char *argv[]){


}

int getRand(int n) {
    int             RVal;
    RVal = (rand() % (n));
    if (RVal == 0) RVal++;
    return (RVal);
}





void printTime(){
  time_t now;
  struct tm newyear;
  double seconds;

  time(&now);  /* get current time; same as: now = time(NULL)  */

  newyear = *localtime(&now);

  newyear.tm_hour = 0; newyear.tm_min = 0; newyear.tm_sec = 0;
  newyear.tm_mon = 0;  newyear.tm_mday = 1;

  seconds = difftime(now,mktime(&newyear));

  printf ("%.f seconds since new year in the current timezone.\n", seconds);

}

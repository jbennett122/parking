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



int main(int argc, char *argv[])
{


	pthread_t carID[N];



    // sem_init(&empty, 0,P);

      if(argc==5){
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

      pthread_attr_init(&attr);

      sem_init(&full, 0, S);
      sem_init(&ending, 0, 0);

      parkingSpots[S];
      vehicle car;


      for(i = 1; i <= C; i++) {

    	//cout<<i<<endl;

    	int car_thread = pthread_create(&carID[i], NULL, &parkCar, (void*)i);

      	  	  }

      sem_wait(&ending);
      cout<<"hi"<<endl;




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



		}

		break;


	}
return i;
	}

void removeCar(int car,int spotNum){


	parkingSpots[spotNum].occupied=false;
}



void *parkCar(void * arg){

	// printf("Car thread #%d\n", (long)arg);

int car=(long)arg;
int timeA,timeW,SN;
int value;


timeW=0;
	 //car enters parking lot display arrival time and spots available
	 r+=getRand(A);
	 timeA=r;

	 if(carInLot==S){
		 cout<<">>> C"<<car<<" Arrived after "<<r<<" seconds...Parking is FULL\n"<<endl;

	 while(carInLot==S){

	 		timeW++;
	 		sleep(1);
	 	}
	 }
	 else {

		 cout<<">>> C"<<car<<" Arrived after "<<r<<" seconds\n"<<endl;

	 }




//cout<<"CarCount "<<carCount<<" C "<<C<<endl;

		sem_getvalue(&full, &value);
		//    printf("The value of the semaphors before is %d\n", value);


	//	 cout<<"CIL "<<carInLot<<endl;
	  sem_wait(&full);

	sem_getvalue(&full, &value);
	 //   printf("The value of the semaphors during is %d\n", value);


	 SN=addCar(car,timeA,timeW);
	 carInLot++;

	 parkTime=getRand(P);

	 cout<<">>> C"<<car<<" parked in S"<<SN<<" after waiting "<<timeW<<" seconds\n"<<endl;

	 sleep(parkTime);

	 cout<<"<<< C"<<car<<" left S"<<SN<<" after "<<parkTime<<" seconds\n"<<endl;
	// cout<<"CIL "<<carInLot<<endl;
	 carCount++;

	 removeCar(car,SN);

	 carInLot--;
	 //cout<<"CIL "<<carInLot<<endl;
	 sem_post(&full);

	 sleep(4);

	    	sem_getvalue(&full, &value);
	   // 	    printf("The value of the semaphors is after %d\n", value);


if((carCount==C)&&(!spotCheck())){

	sem_post(&ending);
	 cout<<"end"<<endl;
}

	 //after parking time up exit the parking lot
	 pthread_exit(NULL);


}

bool spotCheck(){

	bool empty= true;

	for(int i=0;i<S;i++){

		if(parkingSpots[i].occupied==true){
			empty=false;
			break;

		}

	}
	return empty;

}


void lotStatus(int argc, char *argv[]){


}

int getRand(int n) {
    int             RVal;
    RVal = (rand() % (n));
    if (RVal == 0) RVal++;
    return (RVal);
}



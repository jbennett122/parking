/*
 * parking.h
 *
 *  Created on: Apr 7, 2015
 *      Author: hideo
 */

#ifndef PARKING_H_
#define PARKING_H_
#include <vector>


struct vehicle{

	int carNum;
	int timeArrived;
	int timeWaited;
	int timeParked;
	int pSpt;

};

struct spot{

	bool occupied;


	//records vehicle history in spot
	std::vector<vehicle> vhistory;
};



pthread_mutex_t   pSpots[2];

sem_t full;
sem_t ending;

pthread_attr_t  attr;
spot parkingSpots[2];
std::vector<vehicle> carVector;


int i,r,parkTime;
int C,A,S,P;
int car_thread;
long id;
int carCount=1;
int carInLot=0;
time_t rawtime;
time_t beginTime;
time_t endTime;


int getRand(int N);

void *parkCar(void * arg);

int addCar(int car,int timeA,int timeW,int timeP );

void removeCar(int car,int spotNum);

bool spotCheck();

void initSpot();

void lotStatus();

#endif /* PARKING_H_ */

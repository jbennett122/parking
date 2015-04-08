/*
 * parking.h
 *
 *  Created on: Apr 7, 2015
 *      Author: hideo
 */

#ifndef PARKING_H_
#define PARKING_H_



struct vehicle{

	int carNum;
	int timeArrived;
	int timeWaited;


};

struct spot{

	bool occupied;
	vehicle *v;
};



pthread_mutex_t   pSpots[2];

sem_t full;
sem_t empty;

pthread_attr_t  attr;
spot parkingSpots[2];

int i,r,parkTime;
int C,A,S,P;
int car_thread;
long id;



int getRand(int N);

void *parkCar(void * arg);

#endif /* PARKING_H_ */

/*
 * parking.h
 *
 *  Created on: Apr 7, 2015
 *      Author: hideo
 */

#ifndef PARKING_H_
#define PARKING_H_

struct spot{

	bool occupied;

};

struct vehicle{

	int carNum;
	int timeArrived;
	int timeWaited;


};


void *parkCar(void * arg);

#endif /* PARKING_H_ */

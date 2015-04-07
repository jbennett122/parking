//============================================================================
// Name        : parking.cpp
// Author      : Justin Bennett
// Version     : 1
// Copyright   : This belongs to justin
// Description : Parking simulation
//============================================================================

#include <stdio.h>
#include <regex.h>
#include <pthread.h>
#include <sys/socket.h>
#include <unistd.h>
#include <strings.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <string.h>
#include <stdint.h>
#include <fcntl.h>
#include <math.h>
#include <netdb.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <sys/wait.h>
#include <cstdint>
#include <sstream>
#include <errno.h>
#include <semaphore.h>


#define BUFFER_SIZE 10
#define N 5
#define C 3
#define A 3
#define S 2
#define P 20


void *worker_thread(void * arg);

int main(int argc, char *argv[])
{

	spot parkingSpots[S];

	pthread_mutex_t mutex;

	sem_t full;
	sem_t empty;

    pthread_t       tid0;
    pthread_t       tid1;
    pthread_attr_t  attr;
    int i;

    pthread_attr_init(&attr);

    pthread_t my_thread[N];
    pthread_mutex_t   mymutex[N];

    /* Create the full semaphore and initialize to 0 */
      sem_init(&full, 0, 0);


      /* Create the empty semaphore and initialize to BUFFER_SIZE */
      sem_init(&empty, 0, BUFFER_SIZE);




    long id;





    for(id = 1; id <= N; id++) {
    	int ret = pthread_create(&my_thread[id], NULL, &parkCar, (void*)id);
    	if(ret != 0) {
    		printf("Error: pthread_create() failed\n");
    		exit(EXIT_FAILURE);
    	}
    }
    pthread_exit(NULL);
}


void *parkCar(void * arg){

	 printf("Car thread #%ld\n", (long)arg);

	 //car enters parking lot


	 //display arrival time and spots available


	 //car checks to see if there is parking available


	 	 //if parking available park for P time

	 	 	 	 //display spot obtained and time waited


	 	 //else wait one and try again
	 	 	 //increment waiting time


	 //after parking time up exit the parking lot
	 pthread_exit(NULL);






}



void lotStatus(){






}

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

#define N 5

void *worker_thread(void * arg);

int
main(int argc, char *argv[])
{

    pthread_t       tid0;
    pthread_t       tid1;
    pthread_attr_t  attr;
    int             i;

    pthread_attr_init(&attr);

    pthread_t my_thread[N];
    long id;

    for(id = 1; id <= N; id++) {
    	int ret = pthread_create(&my_thread[id], NULL, &worker_thread, (void*)id);
    	if(ret != 0) {
    		printf("Error: pthread_create() failed\n");
    		exit(EXIT_FAILURE);
    	}
    }
    pthread_exit(NULL);
}


void *worker_thread(void * arg){

	 printf("This is worker_thread #%ld\n", (long)arg);

	 pthread_exit(NULL);






}




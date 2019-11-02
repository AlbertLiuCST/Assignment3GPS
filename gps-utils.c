//
// Created by alber on 2019-10-29.
//
#include <stdio.h>
#include <stdlib.h>
#include "gps-utils.h"
#include "gpsprint.h"

/**
Main GPS Loop
*/
void scan(struct gps_data_t *gps_data_ptr){
	int timeout = 500000; // .5 seconds
	int wait = 0;
	while(1){
		if (!gps_waiting(gps_data_ptr, timeout)) {
			if(240 < wait++)
				exit(EXIT_FAILURE);
		} else {
    	    wait = 0;
			if (gps_read(gps_data_ptr) == -1) {
				fprintf(stderr, "gps failed to read");
				exit(1);
			} else {
				if(gps_data_ptr->fix.mode >= MODE_2D 
				&& !isnan(gps_data_ptr->fix.latitude)
				&& !isnan(gps_data_ptr->fix.longitude){
					print(gps_data_ptr);
				}
			}
		} 
	}
}

/**
Function to handle errors
*/



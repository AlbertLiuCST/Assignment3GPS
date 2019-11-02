//
// Created by alber on 2019-10-29.
//
#include <stdio.h>
#include "gps-utils.h"
/**
Main GPS Loop
*/
void scan(struct *gps_data_t gps_data_ptr){
	while(true){
    	if (gps_waiting(gps_data_ptr, 500000)) {
    	    	printf("In GPS waiting\n");
    	    if (gps_read(gps_data_ptr, NULL, 0) == -1) {
    	        printf("Read fail\n");
	     	} else {
         	   	print(gps_data_ptr);
        	}
    	}
    }
}

/**
Function to handle errors
*/



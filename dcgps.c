#include <stdio.h>
#include <stdlib.h>

#include "dcgps.h"
#include "gps-utils.h"

#define LOCAL_HOST "127.0.0.1"
#define PORT "2947"

struct gps_data_t *gps_data_ptr;
static struct fixsource_t source;


int main() {
    //malloc gps_data ptr
    gps_data_ptr = malloc(sizeof(struct gps_data_t));

    source.server = LOCAL_HOST;
    source.port = PORT;
    
    unsigned int flags = WATCH_ENABLE | WATCH_JSON;
    
    if(source.device != NULL)
        flags |= WATCH_DEVICE;
    
    
    if(gps_open(source.server,source.port,gps_data_ptr) != 0){
        
        fprintf(stderr, "No GPSD Running or Network error \n");
        exit(EXIT_FAILURE);
    } else {
        
        if(source.device != NULL)
            flags |= WATCH_DEVICE;
        
        gps_stream(gps_data_ptr, flags, NULL);
        scan(gps_data_ptr);
    }
    
    gps_close(gps_data_ptr);


        
    return 0;
}

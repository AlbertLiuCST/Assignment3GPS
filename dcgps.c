#include <stdio.h>
#include <stdlib.h>
#include <gps.h>

#include "gps-utils.h"


#define LOCAL_HOST "127.0.0.1"
#define PORT "2947"

struct gps_data_t *gps_data_ptr;

int main() {

    gps_data_ptr = malloc(sizeof(struct gps_data_t));

    if(gps_open(LOCAL_HOST,DEFAULT_GPSD_PORT,gps_data_ptr) != 0)
        printf("GPSD Error \n");
    else
        printf("GPSD Working\n");

    (void) gps_stream(gps_data_ptr, WATCH_ENABLE | WATCH_JSON, NULL);
    /* Put this in a loop with a call to a high resolution sleep () in it. */
    while(true){
    if (gps_waiting(gps_data_ptr, 500000)) {
        printf("In GPS waiting\n");
        if (gps_read(gps_data_ptr, NULL, 0) == -1) {
            printf("Read fail\n");
        } else {
            printf("Sat visible:%d ",gps_data_ptr->satellites_visible);
            printf("lat:%f, lon:%f",
                gps_data_ptr->fix.latitude,
                gps_data_ptr->fix.longitude);
        }
    }
    }
        
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <gps.h>

#include "gps-utils.h"


#define LOCAL_HOST "127.0.0.1"
#define PORT "2947"

struct gps_data_t *gps_data_ptr;
static struct fixsource_t source;

int main() {
    //Malloc gps_data ptr
    gps_data_ptr = malloc(sizeof(struct gps_data_t));

    source.server = LOCAL_HOST;
    source.port = PORT;
    source.device = NULL;

    if(gps_open(LOCAL_HOST,DEFAULT_GPSD_PORT,gps_data_ptr) != 0)
        fprintf(stderr, "No GPSD Running or Network error \n");
        exit(EXIT_FAIlURE)
    else
        printf("GPSD Working\n");

    (void) gps_stream(gps_data_ptr, WATCH_ENABLE | WATCH_JSON, NULL);


        
    return 0;
}

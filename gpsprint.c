//
// Created by alber on 2019-10-29.
//
#include "gpsprint.h"

void print(struct gps_data_t *gps_data_ptr){
    if(gps_data_ptr->satellites_visible !=0){
        for(int i = 0; i < gps_data_ptr->satellites_visible; ++i){
            printf("PRN: %3d Elevation: 02%d Azimuth %03d SNR: %02f Used %s\n", 
                gps_data_ptr->skyview[i].PRN,
                gps_data_ptr->skyview[i].elevation,
                gps_data_ptr->skyview[i].azimuth,
                gps_data_ptr->skyview[i].ss,
                gps_data_ptr->skyview[i].used ? "Yes" : "No");
        }
        if(gps_data_ptr->fix.mode >= MODE_2D && isnan(gps_data_ptr->fix.latitude) == 0){
            printf("Latitude: %2f Longitude: %2f", gps_data_ptr->fix.latitude, gps_data_ptr->fix.longitude);
        }
    }
}

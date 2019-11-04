//
// Created by alber on 2019-10-29.
//
#include "gpsprint.h"
/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE:		gpsprint.c -	File prints GPS data
--
-- PROGRAM:       dcgps
--
-- FUNCTIONS:
--					VOID print(struct gps_data_t *gps_data_ptr)
--
-- DATE:			Nov 02, 2019
--
-- REVISIONS:		(N/A)
--
-- DESIGNER:		Albert Liu
--
-- PROGRAMMER:		Albert Liu
--
-- NOTES:
----------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	print
--
-- DATE:		Nov 02, 2019
--
-- REVISIONS:	(N/A)
--
-- DESIGNER:	Albert Liu
--
-- PROGRAMMER:	Albert Liu
--
-- INTERFACE:	VOID print(struct gps_data_t *gps_data_ptr)
--					gps_data_t *gps_data_ptr:	pointer to struct to be used to print gps data from.
--
-- RETURNS:		void
--
-- NOTES:
-- Call this function to print gps data stored in gps object
----------------------------------------------------------------------------------------------------------------------*/
void print(struct gps_data_t *gps_data_ptr){
    if(gps_data_ptr->satellites_visible !=0){
        system("clear");
        
        printf("----------------------------------------------------------------------\n");
        printf("Satellites Visible : %d\n", gps_data_ptr->satellites_visible);
        printf("----------------------------------------------------------------------\n");
        for(int i = 0; i < gps_data_ptr->satellites_visible; ++i){
            printf("PRN: %3d Elevation: 02%d Azimuth %03d SNR: %02f Used %s\n",
                gps_data_ptr->skyview[i].PRN,
                gps_data_ptr->skyview[i].elevation,
                gps_data_ptr->skyview[i].azimuth,
                gps_data_ptr->skyview[i].ss,
                gps_data_ptr->skyview[i].used ? "Yes" : "No");
        }
        printf("----------------------------------------------------------------------\n");
        printTime((time_t *) gps_data_ptr->fix.time);
        printf("Time:%f Latitude: %2f Longitude: %2f\n", gps_data_ptr->fix.time, gps_data_ptr->fix.latitude, gps_data_ptr->fix.longitude);

    }
}

void printTime(time_t tm){
  tm *t = localtime(tm);
  printf("%d-%d-%d %d:%d:%d",
          t->tm_year,
          t->tm_mon,
          t->tm_mday,
          t->tm_hour,
          t->tm_min,
          t->tm_sec,);
}

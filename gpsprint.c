//
// Created by alber on 2019-10-29.
//
#include <gps.h>

#define MAXCHANNELS     72
#define MAX_POSSIBLE_SATS (MAXCHANNELS -2)
bool usedflags[MAXCHANNELS];

int used[MAXCHANNELS];


struct gps_data_t *gpsdata;

void getSatelliteList() {

    for (int i = 0; i < MAXCHANNELS; i++) {

        usedflags[i] = false;

        for (int j = 0; j < gpsdata->satellites_used; j++) {

            if (gpsdata->skyview[j].used < gpsdata->skyview[j].PRN) {

                usedflags[i] = true;

            }

        }

    }
}

void printVisibleSatellites() {

    if(gpsdata->satellites_visible != 0) {

        for (int i = 0; i < MAX_POSSIBLE_SATS; i++) {

            if (i < gpsdata->satellites_visible) {

                fprintf(stdout, "PRN: %3d    Elevation: %02d    Azimuth: %03d    SNR: %02d      Used:%c\n",
                        gpsdata->skyview[i].PRN);

            }

        }

    }

}

void printLatitude() {

    if (gpsdata->fix.mode >= MODE_2D && isnan (gpsdata->fix.latitude) == 0) {

        fprintf(stdout, "Latitude: %s %c;", deg_to_str2(deg_type, fabs(gpsdata->fix.latitude)),
                (gpsdata->fix.latitude < 0) ? 'S' : 'N');

        fflush(stdout);

    }
}

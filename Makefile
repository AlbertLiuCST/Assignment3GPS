CC=gcc -Wall
CLIB=-lgps 

dcgps: dcgps.o gps-utils.o gpsprint.o
	$(CC) -o dcgps dcgps.o gps-utils.o gpsprint.o $(CLIB)

clean:
	rm -f *.o *.gch core.* dcgps
dcgps.o:
	$(CC) -c dcgps.c dcgps.h gps-utils.h
gps-utils.o:
	$(CC) -c gps-utils.c gpsprint.c
gpsprint.o:
	$(CC) -c gpsprint.c

cgps:
	sudo killall gpsd
	sudo gpsd /dev/ttyUSB0 -F /var/run/gpsd.socket
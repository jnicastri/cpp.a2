#
# MakeFile for A2
# Student Name: James Nicastri
# Student No. s3407908
# Unit: CPT323 SP3 2014 - A2
#
#
CC=g++
CFLAGS=-std=c++11 -g -Wall -pedantic
all: myTicSystem.o user.o myTic.o travelPass.o myTicJourney.o myTicStation.o exceptions.o myTicSystemUtils.o adultUser.o juniorUser.o seniorUser.o fullMyTic.o concessionMyTic.o juniorMyTic.o seniorMyTic.o allDayZone1.o allDayZone1And2.o twoHoursZone1.o twoHoursZone1And2.o weeklyZone1.o weeklyZone1And2.o
	$(CC) -o assign2 myTicSystem.o user.o myTic.o travelPass.o myTicJourney.o myTicStation.o exceptions.o myTicSystemUtils.o adultUser.o juniorUser.o seniorUser.o fullMyTic.o concessionMyTic.o juniorMyTic.o seniorMyTic.o allDayZone1.o allDayZone1And2.o twoHoursZone1.o twoHoursZone1And2.o weeklyZone1.o weeklyZone1And2.o
myTicSystem.o: myTicSystem.cpp myTicSystem.h
	$(CC) $(CFLAGS) -c myTicSystem.cpp
user.o: user.cpp user.h
	$(CC) $(CFLAGS) -c user.cpp
myTic.o: myTic.cpp myTic.h
	$(CC) $(CFLAGS) -c myTic.cpp
travelPass.o: travelPass.cpp travelPass.h
	$(CC) $(CFLAGS) -c travelPass.cpp
myTicJourney.o: myTicJourney.cpp myTicJourney.h
	$(CC) $(CFLAGS) -c myTicJourney.cpp
myTicStation.o: myTicStation.cpp myTicStation.h
	$(CC) $(CFLAGS) -c myTicStation.cpp
exceptions.o: exceptions.cpp exceptions.h
	$(CC) $(CFLAGS) -c exceptions.cpp
myTicSystemUtils.o: myTicSystemUtils.cpp myTicSystemUtils.h
	$(CC) $(CFLAGS) -c myTicSystemUtils.cpp
adultUser.o: adultUser.cpp adultUser.h
	$(CC) $(CFLAGS) -c adultUser.cpp
juniorUser.o: juniorUser.cpp juniorUser.h
	$(CC) $(CFLAGS) -c juniorUser.cpp
seniorUser.o: seniorUser.cpp seniorUser.h
	$(CC) $(CFLAGS) -c seniorUser.cpp
fullMyTic.o: fullMyTic.cpp fullMyTic.h
	$(CC) $(CFLAGS) -c fullMyTic.cpp
concessionMyTic.o: concessionMyTic.cpp concessionMyTic.h
	$(CC) $(CFLAGS) -c concessionMyTic.cpp
juniorMyTic.o: juniorMyTic.cpp juniorMyTic.h
	$(CC) $(CFLAGS) -c juniorMyTic.cpp
seniorMyTic.o: seniorMyTic.cpp seniorMyTic.h
	$(CC) $(CFLAGS) -c seniorMyTic.cpp
allDayZone1.o: allDayZone1.cpp allDayZone1.h
	$(CC) $(CFLAGS) -c allDayZone1.cpp
allDayZone1And2.o: allDayZone1And2.cpp allDayZone1And2.h
	$(CC) $(CFLAGS) -c allDayZone1And2.cpp
twoHoursZone1.o: twoHoursZone1.cpp twoHoursZone1.h
	$(CC) $(CFLAGS) -c twoHoursZone1.cpp
twoHoursZone1And2.o: twoHoursZone1And2.cpp twoHoursZone1And2.h
	$(CC) $(CFLAGS) -c twoHoursZone1And2.cpp
weeklyZone1.o: weeklyZone1.cpp weeklyZone1.h
	$(CC) $(CFLAGS) -c weeklyZone1.cpp
weeklyZone1And2.o: weeklyZone1And2.cpp weeklyZone1And2.h
	$(CC) $(CFLAGS) -c weeklyZone1And2.cpp
clean:
	rm -rf *.o

/* 
 * File:   TimeStamp.h
 * Author: carter and tyler
 *
 * Created on September 20, 2012, 4:08 PM
 * This is the timeStamp class header file
 * A timeStamp contains the hour minute  and second a tweet was sent on
 * as well as the month day and year it was sent on
 * below are function to set a time stamp and give formatted outputs of the timeStamp
 */

#ifndef TIMESTAMP_H
#define	TIMESTAMP_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <cstdio>

using namespace std;

class TimeStamp {
public:
	/*constructor, accepts 6 ints from a timestamp in the format MM:DD:YY:HH:MM:SS */
	TimeStamp(int, int, int, int, int, int);
	/* default constructor incase of no parameter input such as in a = new TimeStamp type operation */
	TimeStamp();
	/* deconstructor that is not explicitly used in this class */
	virtual ~TimeStamp();
	/* sets all the member data of the timestamp */
	void setTimeStamp(int, int, int, int, int, int);
	/* sorts the timestamps from newest to oldest */
	void sortStamps();
	/* gets the raw timestamp */
	string getTimeStamp();
	/* gets a very nicely formatted time stamp*/
	string getFormattedTimeStamp();
	/* basic getters and setters */
	int getMonth();
	int getDay();
	int getYear();
	int getHour();
	int getMinute();
	int getSecond();
private:
	int month; /* keeps track of month */
	int day; /* keeps track of day */
	int year; /* keeps track of year */
	int hour; /* keeps track of hour */
	int minute; /* keeps track of minute */
	int second; /* keeps track of second */

};

#endif	/* TIMESTAMP_H */


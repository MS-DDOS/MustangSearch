/* 
 * File:   TimeStamp.cpp
 * Author: carter and tyler
 * 
 * Created on September 20, 2012, 4:08 PM
 *
 * This is the timestamp class and keeps track of the time in (MM:DD:YY:HH:MM:SS) format. This is used for all tweets.
 */

#include "TimeStamp.h"

TimeStamp::TimeStamp(int m, int d, int y, int h, int min, int s) {
	setTimeStamp(m, d, y, h, min, s); //constructor instantiates object's member data.
}

TimeStamp::TimeStamp() //overloaded default constructor in case no data was supplied.
{
	month = 0; //set all values to zero
	day = 0;
	year = 0;
	hour = 0;
	minute = 0;
	second = 0;
}

//TimeStamp::TimeStamp(const TimeStamp& orig) {
//}

TimeStamp::~TimeStamp() {
}

void TimeStamp::setTimeStamp(int m, int d, int y, int h, int min, int s) {
	if ((m < 1) || (m > 12) || (d < 1) || (d > 31) || (y < 1) || (h < 0)
			|| (h > 23) || (min < 0) || (min > 59) || (s < 0) || (s > 59)) { //if statement to ensure no out of bounds values are entered
		cerr << "Invalid Time Stamp parameter: out of bounds"; //report error in case one is out of bounds.
	} else //otherwise instantiate the object
	{
		month = m;
		day = d;
		year = y;
		hour = h;
		minute = min;
		second = s;
	}
}

string TimeStamp::getTimeStamp() //all of the values must be concatenated here for output into a single string
{
	vector<string> output; //this holds all the output elements
	char * temp = new char[100]; //this is just to temporarily hold the value of individual pieces
	string formattedOutput; //this is the final string for output

	if (month < 10) //if the month is less than 10, add a 0 in front of it (for formatting)
		sprintf(temp, "0%1d", month);
	else
		sprintf(temp, "%2d", month); //else just add the number with the precision of two
	output.push_back(temp);

	if (day < 10) //same logic
		sprintf(temp, "0%1d", day);
	else
		sprintf(temp, "%2d", day);
	output.push_back(temp);

	sprintf(temp, "%2d", year);
	output.push_back(temp);

	if (hour < 10) //same logic
		sprintf(temp, "0%1d", hour);
	else
		sprintf(temp, "%2d", hour);
	output.push_back(temp);

	if (minute < 10) //same logic
		sprintf(temp, "0%1d", minute);
	else
		sprintf(temp, "%2d", minute);
	output.push_back(temp);

	if (second < 10) //same lofic
		sprintf(temp, "0%1d", second);
	else
		sprintf(temp, "%2d", second);
	output.push_back(temp);

	//ensures proper formatting of date and time
	for (int x = 0; x < 6; x++) //outputs all elements of the vector into one string.
			{
		formattedOutput += output[x];
		if (x != 5)
			formattedOutput += ":";
	}

	return formattedOutput; //returns the final output string
}

string TimeStamp::getFormattedTimeStamp() //this just returns a formatted version of the above function's string
{
	stringstream str; //sets up a new string stream for output concatenation

	string monthName; //the name of the month in format "March, "
	int twelveHour = hour; //will be used to calculate 12 hour time instead of 24 hour
	string ampm = "am"; //likewise for am/pm output

	switch (month) //to find the string equivalent of the month i.e. 2 => February
	{
	case 1:
		monthName = "January";
		break;

	case 2:
		monthName = "February";
		break;

	case 3:
		monthName = "March";
		break;

	case 4:
		monthName = "April";
		break;

	case 5:
		monthName = "May";
		break;

	case 6:
		monthName = "June";
		break;

	case 7:
		monthName = "July";
		break;

	case 8:
		monthName = "August";
		break;

	case 9:
		monthName = "September";
		break;

	case 10:
		monthName = "October";
		break;

	case 11:
		monthName = "November";
		break;

	case 12:
		monthName = "December";
		break;

	default:
		monthName = "ERROR";
		break;
	}

	/*
	 if(year <= 12)
	 year += 2000;
	 else if(year >= 13)
	 year += 1900;
	 */

	if (hour > 12) //calculates time as 12 hour
			{
		if (hour != 24)
			ampm = "pm";

		twelveHour -= 12;
	}

	//outputs the string but properly formatted with correct zeros for each of the fourcases
	if ((minute < 10) && (second < 10)) {
		str << "at " << twelveHour << ":0" << minute << ":0" << second << ampm
				<< " on " << monthName << " " << day << ", '" << year;
	} else if (minute < 10) {
		str << "at " << twelveHour << ":0" << minute << ":" << second << ampm
				<< " on " << monthName << " " << day << ", '" << year;
	} else if (second < 10) {
		str << "at " << twelveHour << ":" << minute << ":0" << second << ampm
				<< " on " << monthName << " " << day << ", '" << year;
	} else {
		str << "at " << twelveHour << ":" << minute << ":" << second << ampm
				<< " on " << monthName << " " << day << ", '" << year;
	}

	return str.str(); //return the stringstream as a string
}

int TimeStamp::getMonth() {
	return month;
}

int TimeStamp::getDay() {
	return day;
}

int TimeStamp::getYear() {
	return year;
}

int TimeStamp::getHour() {
	return hour;
}

int TimeStamp::getMinute() {
	return minute;
}

int TimeStamp::getSecond() {
	return second;
}

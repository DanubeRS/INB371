/*
    Weekdays (c) Daniel Park 2013

    A simple program which explores the usage of enumeration types.
*/


#include <iostream>
#include <cstdio>
#include <cstdio>
#include <cstdlib>

using namespace std;

//Define an enumeration type specifying weekdays
enum DAYS
{
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

DAYS previousDay(DAYS day);
DAYS nextDay(DAYS day);
DAYS incrementDay(DAYS inDay, int incr);
string getDayName(DAYS day);


int main()
{
    //Inform the user of the program:
    cout << "================================" << endl;
    cout << "|         Forgot My Days       |" << endl;
    cout << "================================" << endl;
    cout << "|    (c)  Daniel Park 2013     |" << endl;
    cout << "|     ***INB371_S1_W3_Q1***    |" << endl;
    cout << "================================" << endl << endl;

    cout << "Wednesday: " << (int)WEDNESDAY << endl;

    DAYS pDay = previousDay(WEDNESDAY);
    DAYS nDay = nextDay(WEDNESDAY);

    cout << "Yesterday: " << pDay << endl;
    cout << "Tomorrow: " << nDay << endl;

    cout << "Monday: " << (int)MONDAY << endl;

    pDay = previousDay(MONDAY);
    nDay = nextDay(MONDAY);

    cout << "Yesterday: " << pDay << endl;
    cout << "Tomorrow: " << nDay << endl;

    DAYS today = THURSDAY;

    cout << "Today is: " << (int)today << endl;
    cout << "(Well not really, but for the sake of argument, lets say it is)" << endl;
    cout << "\t How many days from today do you want to be?:" << endl;

    int incrDays;
    cin >> incrDays;

    cout << incrDays << " from " << getDayName(today) << " is " << getDayName(incrementDay(today, incrDays)) << endl;
    return 1;

}

DAYS nextDay(DAYS inDay)
{


    //test if day causes loopback (i.e, keep within enumeraation bounds)
    if ( inDay == SUNDAY)
    {
        return MONDAY;
    }
    else
    {
        return (DAYS)(inDay + 1);   //Else, decrement day by 1
    }
}

DAYS previousDay(DAYS inDay)
{


    //test if day causes loopback (i.e, keep within enumeraation bounds)
    if ( inDay == MONDAY)
    {
        return SUNDAY;
    }
    else
    {
        return (DAYS)(inDay - 1);   //Else, decrement day by 1
    }
}

DAYS incrementDay(DAYS inDay, int incr)
{

    DAYS tempDay = inDay;
    int direction;
    if (incr > 0)
    {
        direction = 1;
    }
    else if (incr < 0)
    {
        direction = -1;
    }

    for (int i = 0; i < abs(incr); i++)
    {
        if (tempDay == SUNDAY && direction == 1)
        {
            tempDay = MONDAY;
        }
        else
        {
            tempDay = (DAYS)(tempDay - 1);
        }
        if (tempDay == MONDAY && direction == -1)
        {
            tempDay = MONDAY;
        }
    }
    return tempDay;

}

string getDayName(DAYS day)
{
    switch ((int)day)
    {
    case 1:
        return "Monday";
    case 2:
        return "Tuesday";
    case 3:
        return "Wednesday";
    case 4:
        return "Thursday";
    case 5:
        return "Friday";
    case 6:
        return "Saturday";
    case 7:
        return "Sunday";
    }

}
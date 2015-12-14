#define _CRT_SECURE_NO_WARNINGS

#include <cmath>

#include <iostream>
using std::ostream;
using std::istream;
using std::cout;

class Time
{
private:
  int hours;
  int minutes;
  int seconds;
  char *interval;

public:
  Time() : hours(0), minutes(0), seconds(0)
  {
    interval = new char[1] ();
  }

  Time(int hours1, int minutes1, int seconds1) : hours(hours1), minutes(minutes1), seconds(seconds1)
  {
    interval = new char[1] ();
  }

  Time(int hours1, int minutes1, int seconds1, const char* interval1) : hours(hours1), minutes(minutes1), seconds(seconds1)
  {
    delete[]interval;
    interval = new char[strlen(interval1) + 1];
    strcpy(interval, interval1);
  }

  Time(const Time& obj) : hours(obj.hours), minutes(obj.minutes), seconds(obj.seconds)
  {
    delete[]interval;
    interval = new char[strlen(obj.interval) + 1];
    strcpy(interval, obj.interval);
  }

  Time(Time&& obj) : hours(obj.hours), minutes(obj.minutes), seconds(obj.seconds), interval(obj.interval)
  {    
    obj.hours = 0;
    obj.minutes = 0;
    obj.seconds = 0;
    obj.interval = nullptr;
  }

  friend const Time SecondsToTime( const int sec );
  friend const int TimeToSeconds( const Time& obj );
  friend const Time _24To12( const Time& obj );
  friend const Time _12To24( const Time& obj );

  Time& operator = ( Time&& obj )
  {
    if (this == &obj) return obj;

    hours = obj.hours;
    minutes = obj.minutes;
    seconds = obj.seconds;
    interval = obj.interval;

    obj.hours = 0;
    obj.minutes = 0;
    obj.seconds = 0;
    obj.interval = nullptr;

    return *this;
  }

  Time operator + ( const Time& obj ) const;
  Time operator - ( const Time& obj ) const;
  bool operator == ( const Time& obj ) const;
  bool operator != ( const Time& obj ) const;
  bool operator < ( const Time& obj ) const;
  bool operator > ( const Time& obj ) const;

  friend bool operator >= ( const Time& obj1, const Time& obj2 );
  friend bool operator <= ( const Time& obj1, const Time& obj2 );
  friend ostream& operator << ( ostream& os, const Time& obj );
  friend istream& operator >> ( istream& is, Time& obj );

  ~Time() { delete []interval; }
};
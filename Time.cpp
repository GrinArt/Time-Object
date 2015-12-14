#include "Time.h"

const Time SecondsToTime(const int sec)
{
  Time t;

  for (int i = 0; i < sec; i++)
  {
    t.seconds++;
    if ( t.seconds >= 60 ) { t.minutes++; t.seconds -= 60; }
    if ( t.minutes >= 60 ) { t.hours++; t.minutes -= 60; }
    if ( t.hours >= 24 ) { t.hours = 0; }
  }

  return t;
}

const int TimeToSeconds(const Time& obj)
{
  return obj.hours * 3600 + obj.minutes * 60 + obj.seconds;
}

const Time _24To12(const Time& obj)
{
  Time t;

  if ( TimeToSeconds(obj) > 12*3600 )
  {
    t = SecondsToTime(TimeToSeconds(obj) - 12 * 3600);
    t.interval = new char[8];
    strcpy(t.interval, "p.m.");
  }
  else
  {
    if (TimeToSeconds(obj) == 0)
    {
      t = SecondsToTime( 12 * 3600 );
      t.interval = new char[16];
      strcpy(t.interval, "m.n.");
    }
    else
    {
      t = obj;
      t.interval = new char[16];
      if (TimeToSeconds(obj) == 12 * 3600) strcpy(t.interval, "m.d.");
      else strcpy(t.interval, "a.m.");
    }
  }

  return t;
}

const Time _12To24(const Time& obj)
{
  Time t;

  if ( strcmp(obj.interval, "p.m.") == 0 ) t = SecondsToTime( TimeToSeconds(obj) + 12 * 3600 );
  else
  {
    if ( strcmp(obj.interval, "m,d.") == 0 ) t = SecondsToTime( 12 * 3600 );
    else if ( strcmp(obj.interval, "m.n." ) == 0) t = SecondsToTime(0);
    else t = obj;
  }

  t.interval = new char[1]();

  return t;
}


Time Time::operator + (const Time& obj) const
{
  return SecondsToTime( TimeToSeconds(obj) + TimeToSeconds(*this) );
}

Time Time::operator - (const Time& obj) const
{
  return SecondsToTime( abs(TimeToSeconds(obj) - TimeToSeconds(*this)) );
}

bool Time::operator == (const Time& obj) const
{
  if ( TimeToSeconds(obj) == TimeToSeconds(*this) ) return true; return false;
}

bool Time::operator > (const Time& obj) const
{
  if ( TimeToSeconds(obj) > TimeToSeconds(*this) ) return true; return false;
}

bool Time::operator < (const Time& obj) const
{
  if ( TimeToSeconds(obj) < TimeToSeconds(*this) ) return true; return false;
}

bool operator >= (const Time& obj1, const Time& obj2)
{
  if ( TimeToSeconds(obj1) >= TimeToSeconds(obj1) ) return true; return false;
}

bool operator <= (const Time& obj1, const Time& obj2)
{
  if ( TimeToSeconds(obj1) <= TimeToSeconds(obj1) ) return true; return false;
}

bool Time::operator != (const Time& obj) const
{
  if ( TimeToSeconds(obj) != TimeToSeconds(*this) ) return true; return false;
}

ostream& operator << (ostream& os, const Time& obj)
{
  printf("%02d:%02d:%02d %s", obj.hours, obj.minutes, obj.seconds, obj.interval);

  return os;
}

istream& operator >> (istream& is, Time& obj)
{
  cout << "Please, enter the time: \n";
  cout << "Hours: ";
  is >> obj.hours;
  cout << "Minutes: ";
  is >> obj.minutes;
  cout << "Seconds: ";
  is >> obj.seconds;

  return is;
}
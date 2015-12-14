#include "Time.h"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
  Time t1(14, 9, 50);
  Time t2(11, 50, 12);
  Time t3, t4(12, 0, 0);

  cout << t1 << endl;
  cout << t2 << endl;

  cout << t1 + t2 << endl;
  cout << t1 - t2 << endl;

  cout << _24To12(t1) << endl;
  cout << _24To12(t2) << endl;

  cout << _12To24( _24To12(t1) ) << endl;
  cout << _12To24( _24To12(t2) ) << endl;

  cout << _24To12(t3) << endl;
  cout << _24To12(t4) << endl;

  cout << _12To24( _24To12(t3) ) << endl;
  cout << _12To24( _24To12(t4) ) << endl;



  system("pause");

  return 0;
}
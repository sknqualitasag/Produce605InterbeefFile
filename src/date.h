#ifndef Date_h
#define Date_h
#include <sstream>

using namespace std;

class date{
public:

  int YearInt;
  string YearStr;
  int MonthInt;
  string MonthStr;
  int DayInt;
  string DayStr;

  date(string datestr);
  date();

  long int DateInDays;

  bool isValid;



};

#endif

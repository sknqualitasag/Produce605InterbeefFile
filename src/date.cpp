#include <cstdlib>
#include "date.h"
#include "constant.h"
#include "juldate.h"


using namespace std;

date::date(){}


date::date(string datestr){

  if(datestr.size() == 8){

    isValid = true;

    YearStr = datestr.substr(0,4).c_str();
    YearInt = atoi(YearStr.c_str());
    if(YearInt < 1950) {
      YearInt = CONSTANTS::INT_NA;
      YearStr = CONSTANTS::STRING_NA;
      isValid = false;
    }

    MonthStr = datestr.substr(4,2).c_str();
    MonthInt=atoi(MonthStr.c_str());
    if(MonthInt<1 || MonthInt>12) {
      MonthInt = CONSTANTS::INT_NA;
      MonthStr = CONSTANTS::STRING_NA;
      isValid = false;
    }

    DayStr = datestr.substr(6,2).c_str();
    DayInt=atoi(DayStr.c_str());
    if(DayInt<1 || DayInt>31) {
      DayInt = CONSTANTS::INT_NA;
      DayStr = CONSTANTS::STRING_NA;
      isValid = false;
    }

    DateInDays =  julDate(YearStr, MonthStr, DayStr);


  }else{
    YearInt = CONSTANTS::INT_NA;
    YearStr = CONSTANTS::STRING_NA;
    MonthInt = CONSTANTS::INT_NA;
    MonthStr = CONSTANTS::STRING_NA;
    DayInt = CONSTANTS::INT_NA;
    DayStr = CONSTANTS::STRING_NA;
    DateInDays = CONSTANTS::INT_NA;
    isValid = false;

  }

}

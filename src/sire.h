#ifndef Sire_h
#define Sire_h
#include <set>
#include <sstream>
#include <vector>
#include <map>
#include "date.h"

using namespace std;

class sire{
public:

  string indStr, traitStr, indBreedStr, sexBirthStr, itbidStr, inditbbreedStr, indDbIdStr, damDbIdStr, sireDbIdStr;
  double accDbl;
  date birthdate;

  sire(string indstr, string traitname, double acc, string indbreedstr, date indbirthdate, string itbidstr, string sexstr, string inditbbreedstr, string indDbIdstr, string damDbIdstr, string sireDbIdstr, string psRunningMode);

  void constructorDebug(string message, string tvdid, string psRunningMode);

};


#endif

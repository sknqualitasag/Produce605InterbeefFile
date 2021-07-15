#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <strstream>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <functional>
#include <cstring>
#include "animal.h"
#include "rutil.h"
#include "constant.h"
#include "date.h"
#include <plog/Log.h>



using namespace std;

animal::animal(string indstr, string traitname, double acc, string psRunningMode, string statusOfBullstr){

  indStr = indstr;
  constructorDebug("constructor animal()_Constructor called with indStr ", indStr, psRunningMode);
  traitStr = traitname;
  constructorDebug("constructor animal()_Constructor called with traitStr "+traitStr, indStr, psRunningMode);
  accDbl = acc;
  constructorDebug("constructor animal()_Constructor called with accDbl "+to_string(accDbl), indStr, psRunningMode);
  statusOfBullStr = statusOfBullstr;
  constructorDebug("constructor animal()_Constructor called with statusOfBullStr "+statusOfBullStr, indStr, psRunningMode);

}


// Constructor using DB-Ids of animal, sire and dam as additional arguments
animal::animal(string indstr, string indbreedstr, date indbirthdate, string itbidstr, string sexstr, string indactivstr, string indhbstr, string inditbbreedstr, string indDbIdstr, string damDbIdstr, string sireDbIdstr, string psRunningMode){

  indStr = indstr;
  constructorDebug("constructor animal()_Constructor called with indStr ", indStr, psRunningMode);
  indactivStr = indactivstr;
  constructorDebug("constructor animal()_Constructor called with indactivStr "+indactivStr, indStr, psRunningMode);
  indhbStr = indhbstr;
  constructorDebug("constructor animal()_Constructor called with indhbStr "+indhbStr, indStr, psRunningMode);
  inditbbreedStr = inditbbreedstr;
  constructorDebug("constructor animal()_Constructor called with inditbbreedStr "+inditbbreedStr, indStr, psRunningMode);
  indDbIdStr = indDbIdstr;
  constructorDebug("constructor animal()_Constructor called with indDbIdStr "+indDbIdStr, indStr, psRunningMode);
  damDbIdStr = damDbIdstr;
  constructorDebug("constructor animal()_Constructor called with damDbIdStr "+damDbIdStr, indStr, psRunningMode);
  sireDbIdStr = sireDbIdstr;
  constructorDebug("constructor animal()_Constructor called with sireDbIdStr "+sireDbIdStr, indStr, psRunningMode);
  indBreedStr = indbreedstr;
  constructorDebug("constructor animal()_Constructor called with indBreedStr "+indBreedStr, indStr, psRunningMode);
  sexBirthStr = sexstr;
  constructorDebug("constructor animal()_Constructor called with sexBirthStr "+sexBirthStr, indStr, psRunningMode);
  itbidStr = itbidstr;
  constructorDebug("constructor animal()_Constructor called with itbidStr "+itbidStr, indStr, psRunningMode);
  birthdate = indbirthdate;
  constructorDebug("constructor animal()_Constructor called with birthdate "+birthdate.YearStr+birthdate.MonthStr+birthdate.DayStr, indStr, psRunningMode);


}


// constructor debug File
void animal::constructorDebug(string message, string tvdid, string psRunningMode){
  string localRunningMode = psRunningMode;
  if(localRunningMode == CONSTANTS::RUNNING_DEBUGALL){
    //here Develop-Output-Logfile
    LOGD <<"Message "<<message<<" of animal "<<tvdid;
  }
}

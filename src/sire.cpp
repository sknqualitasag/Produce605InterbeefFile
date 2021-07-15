#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <sstream>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <stdio.h>
#include <cstring>
#include <plog/Log.h>
#include "sire.h"
#include "date.h"
#include "constant.h"




using namespace std;


sire::sire(string indstr, string traitname, double acc, string indbreedstr, date indbirthdate, string itbidstr, string sexstr, string inditbbreedstr, string indDbIdstr, string damDbIdstr, string sireDbIdstr, string psRunningMode, string statusOfBullstr){

  indStr = indstr;
  constructorDebug("constructor sire()_Constructor called with indStr ", indStr, psRunningMode);
  traitStr = traitname;
  constructorDebug("constructor sire()_Constructor called with traitStr "+traitStr, indStr, psRunningMode);
  accDbl = acc;
  constructorDebug("constructor sire()_Constructor called with accDbl "+to_string(accDbl), indStr, psRunningMode);
  indBreedStr = indbreedstr;
  constructorDebug("constructor sire()_Constructor called with indBreedStr "+indBreedStr, indStr, psRunningMode);
  birthdate = indbirthdate;
  constructorDebug("constructor sire()_Constructor called with birthdate "+birthdate.YearStr+birthdate.MonthStr+birthdate.DayStr, indStr, psRunningMode);
  itbidStr = itbidstr;
  constructorDebug("constructor sire()_Constructor called with itbidStr "+itbidStr, indStr, psRunningMode);
  sexBirthStr = sexstr;
  constructorDebug("constructor sire()_Constructor called with sexBirthStr "+sexBirthStr, indStr, psRunningMode);
  inditbbreedStr = inditbbreedstr;
  constructorDebug("constructor sire()_Constructor called with inditbbreedStr "+inditbbreedStr, indStr, psRunningMode);
  indDbIdStr = indDbIdstr;
  constructorDebug("constructor sire()_Constructor called with indDbIdStr "+indDbIdStr, indStr, psRunningMode);
  damDbIdStr = damDbIdstr;
  constructorDebug("constructor sire()_Constructor called with damDbIdStr "+damDbIdStr, indStr, psRunningMode);
  sireDbIdStr = sireDbIdstr;
  constructorDebug("constructor sire()_Constructor called with sireDbIdStr "+sireDbIdStr, indStr, psRunningMode);
  statusOfBullStr = statusOfBullstr;
  constructorDebug("constructor sire()_Constructor called with statusOfBullStr "+statusOfBullStr, indStr, psRunningMode);


}


// constructor debug File
void sire::constructorDebug(string message, string tvdid, string psRunningMode){
  string localRunningMode = psRunningMode;
  if(localRunningMode == CONSTANTS::RUNNING_DEBUGALL){
    //here Develop-Output-Logfile
    LOGD <<"Message "<<message<<" of animal "<<tvdid;
  }
}

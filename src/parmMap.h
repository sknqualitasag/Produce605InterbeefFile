#ifndef PARM_MAP_H
#define PARM_MAP_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <sstream>


using namespace std;
class ParmMap: public map<std::string,std::string> {
public:
  string fileName;
  void inputParms(void);
  double getDouble(string parmName);
  unsigned getUnsigned(string parmName);
  int getInteger(string parmName);
  string getString(string parmName);
  bool getBoolean(string parmName);
  char* getCharPtr(string parmName);

};

#endif

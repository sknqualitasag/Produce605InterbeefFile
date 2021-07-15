#ifndef BloodlMap_h
#define BloodlMap_h
#include <set>
#include <sstream>
#include <vector>
#include <map>
#include "blood.h"

using namespace std;

class bloodMap : public map<string,blood*>{
private:

  string runningMode;

public:

  bloodMap(void);
  void makeReadableBloodComposite(string bloodFile, string bloodFileReformattted);

  void setRunningMode(string psRunningMode);
  string getRunningMode();
  void simpleDebug(string message, string tvdid);


};

#endif

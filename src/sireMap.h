#ifndef SireMap_h
#define SireMap_h
#include <set>
#include <sstream>
#include <vector>
#include <map>
#include "sire.h"
#include "animalMap.h"
#include "bloodMap.h"

using namespace std;

class sireMap : public map<string,sire*>{
private:

  string runningMode;

public:

  sireMap(void);
  void mergeAllInputs(animalMap &aMap, animalMap &pMap);
  void outputInterbeef605(string psBreed, string parInterbeefTraitName);
  string convertBreed2InterbullBreed(string psBreed);
  bool purgeBloodcomposite(string indDbIdStr, string parBreedName);
  bloodMap BreedComposite;


  void setRunningMode(string psRunningMode);
  string getRunningMode();
  void simpleDebug(string message, string tvdid);
  void To_out();


};

#endif

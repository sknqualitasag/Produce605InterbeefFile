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
#include <chrono>
#include <ctime>
#include "sireMap.h"
#include "date.h"
#include "constant.h"

using namespace std;

sireMap::sireMap(){}


void sireMap::mergeAllInputs(animalMap &aMap, animalMap &pMap){

  cout<<"\nmergeAllInputs(): mergeAllInputs in sireMap "<<endl;
  cout<<"*****************************************************************"<< endl;

  //pMap ist mit numerischeID Tier.
  for(map<string,animal*>::iterator pit = pMap.begin(); pit != pMap.end();  pit++){
    //aMap ist mit den TVD-ID von Tier aufgebaut.
    map<string, animal*>::iterator itTVD = aMap.find(pit->second->indStr);
    // itTVD found in aMap
    if(itTVD != aMap.end()){

      string psRunningMode = getRunningMode();

      cout<<"indStr: "<<itTVD->second->indStr<<" "<<"statusOfBullStr: "<<itTVD->second->statusOfBullStr<<endl;

      // new sire record
      sire *sPtr = new sire(itTVD->second->indStr, itTVD->second->traitStr, itTVD->second->accDbl, pit->second->indBreedStr, pit->second->birthdate, pit->second->itbidStr, pit->second->sexBirthStr, pit->second->inditbbreedStr, pit->second->indDbIdStr, pit->second->damDbIdStr, pit->second->sireDbIdStr, psRunningMode);

      (*this)[pit->second->indDbIdStr] = sPtr;
      simpleDebug("mergeAllInputs()_Input Line pit->second->indDbIdStr " + pit->second->indDbIdStr, pit->second->indDbIdStr);


    }

  }

}


void sireMap::outputInterbeef605(string psBreed, string parInterbeefTraitName){

  string itbBreed=convertBreed2InterbullBreed(psBreed);


  cout<<"\noutputInterbeef605(): WRITING INTERBEEF DATA-FILE FOR "<<itbBreed<<" AND "<<parInterbeefTraitName<<endl;
  cout<<"*****************************************************************"<< endl;

  ofstream datafile605("datafile605_"+itbBreed+"_"+parInterbeefTraitName);

  for(map<string,sire*>::iterator it = this->begin();it != this->end(); it++){
    sire *sPtr =(*it).second;

    if(sPtr->indBreedStr == psBreed){

      simpleDebug("outputInterbeef605()_breed " + sPtr->indBreedStr +" of sireID "+sPtr->indDbIdStr, sPtr->indStr);

      if(purgeBloodcomposite(sPtr->indDbIdStr, psBreed)){

        simpleDebug("outputInterbeef605()_write sireID "+sPtr->indDbIdStr+" in 605-file", sPtr->indStr);

        datafile605 <<setw(3)<<"605"
                    <<setw(4)<<sPtr->inditbbreedStr
                    <<setw(16)<<sPtr->itbidStr.substr(2,16)
                    <<setw(3)<<sPtr->accDbl*100
                    <<setw(3)<<"00"
                    <<setw(4)<<"CHE"<<endl;

      }

    }

  }


}


string sireMap::convertBreed2InterbullBreed(string psBreed){

  if(psBreed == "AN") return("AAN");
  else if(psBreed == "CH") return("CHA");
  else if(psBreed == "HH") return("HER");
  else if(psBreed == "LM") return("LIM");
  else if(psBreed == "SI") return("SIM");
  else return("XXX");

}


bool sireMap::purgeBloodcomposite(string indDbIdStr, string parBreedName){

  map<string, blood*>::iterator bit=BreedComposite.find(indDbIdStr);
  if(bit != BreedComposite.end()){
    if(bit->second->BloodComposite[parBreedName] < CONSTANTS::MIN_BLOOD_CONTENT){
      simpleDebug("purgeBloodcomposite()_parBreedName " + parBreedName + " ,bloodComposite to low "+ to_string(bit->second->BloodComposite[parBreedName]), indDbIdStr);
      return false;
    }else{
      simpleDebug("purgeBloodcomposite()_parBreedName " + parBreedName + " ,bloodComposite respect the minimum "+ to_string(bit->second->BloodComposite[parBreedName]), indDbIdStr);
      return true;
    }
  }else{
    simpleDebug("purgeBloodcomposite()_breedComposite doesn't countain", indDbIdStr);
    return false;
  }

}


// setter for running mode
void sireMap::setRunningMode(string psRunningMode){
  runningMode = psRunningMode;

}


// getter for running mode
string sireMap::getRunningMode(){
  return runningMode;
}


// simple debug File
void sireMap::simpleDebug(string message, string tvdid){
  string localRunningMode = getRunningMode();
  if(localRunningMode == CONSTANTS::RUNNING_DEBUGALL){
    //here Develop-Output-Logfile
    LOGD <<"Message "<<message<<" of animal "<<tvdid;
  }
}


void sireMap::To_out(){
  cout<<"\nTo_out()"<<endl;
  cout<<"*****************************************************************"<< endl;

  for(map<string, sire*>::iterator it=begin();it!=end();it++){
    sire *ptr = (*it).second;
    cout<<"ptr->indStr "<<ptr->indStr<<", ptr->indBreedStr "<<ptr->indBreedStr<<", ptr->indDbIdStr "<<ptr->indDbIdStr<<", ptr->itbidStr "<<ptr->itbidStr <<endl;
  }
}

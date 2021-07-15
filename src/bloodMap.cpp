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
#include "animalMap.h"
#include <plog/Log.h>
#include "constant.h"
#include <chrono>
#include <ctime>
#include "bloodMap.h"
#include "rutil.h"

using namespace std;

bloodMap::bloodMap(){

  cout<<"\nbloodMap(): bloodMap building "<<endl;
  cout<<"*****************************************************************"<< endl;

}



//' Make readable blood composite file
void bloodMap::makeReadableBloodComposite(string bloodFile, string bloodFileReformattted){

  cout<<"\nmakeReadableBloodComposite(): Reformatting the file "<<bloodFile<<" writing "<<bloodFileReformattted<<endl;
  cout<<"*****************************************************************"<< endl;

  ifstream datafile(bloodFile.c_str());
  if(!datafile){
    cout<< "Cannot open file "<< bloodFile<<" in makeReadableBloodComposite()! \n";
    exit(1);
  }

  ofstream outputfile(bloodFileReformattted.c_str());
  if(!outputfile){
    cout<< "Cannot open output file! \n";
    exit(1);
  }


  datafile.setf(ios::skipws);
  string sep(" ");
  Tokenizer colData;
  string inputStr;
  string indnumstr;
  string breedcodestr_;
  string bloodcodestr_;
  unsigned lineNumber=0, numCols=0;
  unsigned numberOfBreed=0;
  unsigned numberElementPerBreed = 2;
  unsigned currentBreedBlood = 0;


  // reading blood composite file line by line
  while(getline(datafile,inputStr)){
    colData.getTokens(inputStr,sep);
    lineNumber++;
    numCols = colData.size();

    //Extract field animalID of the line
    indnumstr = colData[0];
    simpleDebug("makeReadableBloodComposite()_numCols are " + to_string(numCols), indnumstr);

    //Extract field of the line containing breed and blood composite
    numberOfBreed = (numCols - 1)/numberElementPerBreed;

    blood *bPtr = new blood();

    //Build BloodComposite-Map for an animalID
    for(int i = 1; i<= numberOfBreed; i++){
      bPtr->BloodComposite[colData[(i-1)*numberElementPerBreed+1]] = stoi(colData[i*numberElementPerBreed]);
      simpleDebug("makeReadableBloodComposite()_breedcode is " + colData[(i-1)*numberElementPerBreed+1] + " and bloodcomposite is " + colData[i*numberElementPerBreed], indnumstr);
    }

    (*this)[indnumstr] = bPtr;
    simpleDebug("makeReadableBloodComposite()_Insert BloodComposite-Map ", indnumstr);
  }

  datafile.close();
  outputfile.close();
  cout<<"Read "<<lineNumber<<" lines"<<endl;


}



// setter for running mode
void bloodMap::setRunningMode(string psRunningMode){
  runningMode = psRunningMode;

}


// getter for running mode
string bloodMap::getRunningMode(){
  return runningMode;
}


// simple debug File
void bloodMap::simpleDebug(string message, string tvdid){
  string localRunningMode = getRunningMode();
  if(localRunningMode == CONSTANTS::RUNNING_DEBUGALL){
    //here Develop-Output-Logfile
    LOGD <<"Message "<<message<<" of animal "<<tvdid;
  }
}

#include "parmMap.h"

using namespace std;

void ParmMap::inputParms(void){

  ifstream inFile(this->fileName.c_str());
  if(!inFile) {
    std::cerr << "Couldn't open parmFile: " <<this->fileName << std::endl;
    exit (-1);
  }

  string parmName, parmValue;
  ParmMap::iterator mapit;
  while (inFile >> parmName >> parmValue){
    mapit = find(parmName);
    if(mapit== end()){
      (*this)[parmName]=parmValue;
    }
    else {
      cout<<"Parameter "<<parmName<<" already set, please check whether it occurs twice in your parameter file."<<endl;
    }
  }
  cout<<"\nLIST OF PARAMETERS:"<<endl;
  cout<<"*****************************************************************"<< endl;
  for(ParmMap::iterator it=begin(); it!=end(); it++){
    cout<<it->first<<"\t"<<it->second<<endl;
  }
}

double ParmMap::getDouble(string parmName){
  ParmMap::iterator mapit = find(parmName);
  if(mapit== end()){
    cout << "getDouble(): Unrecognized parameter in ParameterFile "<<fileName<<": " << parmName << std::endl;
    exit(111);
  }
  string parmValue = mapit->second;
  istringstream istr(parmValue);
  double doubleValue;
  istr >> doubleValue;
  return doubleValue;
}

bool ParmMap::getBoolean(string parmName){
  ParmMap::iterator mapit = find(parmName);
  if(mapit== end()){
    cout << "getBoolean(): Unrecognized parameter in ParameterFile "<<fileName<<": " << parmName << std::endl;
    exit(111);
  }
  string parmValue = mapit->second;
  istringstream istr(parmValue);
  //	bool boolValue;
  if(parmValue =="true") return true;
  else if(parmValue =="false") return false;

  else{
    cout << "getBoolean(): Unrecognized parameterValue "<<parmValue<<" in ParameterFile "<<fileName<<": " << parmName <<std::endl;
    exit(111);
  }

}

string ParmMap::getString(string parmName){
  ParmMap::iterator mapit = find(parmName);
  if(mapit== end()){
    cout << "getString(): Unrecognized parameter in ParameterFile "<<fileName<<": " << parmName << std::endl;
    exit(111);
  }
  string parmValue = mapit->second;
  return parmValue;
}

char* ParmMap::getCharPtr(string parmName){
  ParmMap::iterator mapit = find(parmName);
  if(mapit== end()){
    cout << "getCharPtr(): Unrecognized parameter in ParameterFile "<<this->fileName<<": " << parmName << std::endl;
    exit(111);
  }
  char* parmValue = (char*)(mapit->second).c_str();
  return parmValue;
}

unsigned ParmMap::getUnsigned(string parmName){
  ParmMap::iterator mapit = find(parmName);
  if(mapit== end()){
    cout << "getUnsigned(): Unrecognized parameter in ParameterFile "<<fileName<<": " << parmName << std::endl;
    exit(111);
  }
  string parmValue = mapit->second;
  istringstream istr(parmValue);
  unsigned unsignedValue;
  istr >> unsignedValue;
  return unsignedValue;
}

int ParmMap::getInteger(string parmName){
  ParmMap::iterator mapit = find(parmName);
  if(mapit== end()){
    cout << "getUnsigned(): Unrecognized parameter in ParameterFile "<<fileName<<": " << parmName << std::endl;
    exit(111);
  }
  string parmValue = mapit->second;
  istringstream istr(parmValue);
  int intValue;
  istr >> intValue;
  return intValue;
}


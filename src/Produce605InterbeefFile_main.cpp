#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <Rcpp.h>
#include <plog/Log.h>
#include "parmMap.h"
#include "bloodMap.h"
#include "constant.h"
#include "sireMap.h"



using namespace Rcpp;


enum{
SecondLog = 1,
};


// [[Rcpp::export]]
int Produce605InterbeefFile_main(std::string paramFileName) {

  //Time tracking
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  time_t start_time = std::chrono::system_clock::to_time_t(start);



  std::cout<<"-----------------------------------------------------------------"<< std::endl;
  std::cout << "START Produce605InterbeefFile_main() at " << std::ctime(&start_time) << std::endl;
  std::cout<<"-----------------------------------------------------------------"<< std::endl;

  std::cout<<"ParameterFile = "<<paramFileName<<std::endl;
  ParmMap parmMap;
  parmMap.fileName = paramFileName;
  parmMap.inputParms();

  std::string dataFile  							        = parmMap.getString("dataFileName");
  std::string FileWithStatusOfBull            = parmMap.getString("FileNameWithStatusOfBull");
  std::string bloodFile							          = parmMap.getString("bloodFileName");
  std::string bloodFileReformattted	          = bloodFile+".reformatted";
  std::string pedigreeFile							      = parmMap.getString("pedigreeFileName");
  std::string pedigreeFileReformatted     	  = pedigreeFile+".reformatted";
  std::string parInterbeefTraitName           = parmMap.getString("InterbeefTraitName");


  animalMap aMap;
  animalMap pMap;
  sireMap sMap;
  bloodMap bMap;

  //Debugging-File
//  plog::init(plog::debug, "DEBUG_605Interbeef_Output.txt");

  //Read blood composite file
//  bMap.setRunningMode(CONSTANTS::RUNNING_DEBUGALL);
  bMap.makeReadableBloodComposite(bloodFile, bloodFileReformattted);
  sMap.BreedComposite = bMap;

  //Read data file
//  aMap.setRunningMode(CONSTANTS::RUNNING_DEBUGALL);
  aMap.inputData(dataFile);

  //Read pedigree file
//  pMap.setRunningMode(CONSTANTS::RUNNING_DEBUGALL);
  pMap.makeReadableRRTDMPedigree(pedigreeFile,pedigreeFileReformatted);
  pMap.readRRTDMPedigree(pedigreeFileReformatted);

  //Create a sire map
//  sMap.setRunningMode(CONSTANTS::RUNNING_DEBUGALL);
  sMap.mergeAllInputs(aMap, pMap);

  //Output 605 Interbeef file
  sMap.outputInterbeef605(CONSTANTS::AN_INTERBEEFBREED,parInterbeefTraitName);
  sMap.outputInterbeef605(CONSTANTS::CH_INTERBEEFBREED,parInterbeefTraitName);
  sMap.outputInterbeef605(CONSTANTS::LM_INTERBEEFBREED,parInterbeefTraitName);
  sMap.outputInterbeef605(CONSTANTS::SM_INTERBEEFBREED,parInterbeefTraitName);


  //Time tracking
  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  std::cout<<"\n-----------------------------------------------------------------"<< std::endl;
  std::cout << "END Produce605InterbeefFile_main() at " << std::ctime(&end_time)
            << "elapsed time: " << elapsed_seconds.count() << " s"<<std::endl;
  std::cout<<"-----------------------------------------------------------------"<< std::endl;


  return 0;
}

//With RConsole ausführen
/*** R
Produce605InterbeefFile_main()
  */
